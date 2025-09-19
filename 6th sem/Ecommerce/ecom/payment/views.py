from django.shortcuts import render, redirect
from cart.cart import Cart
from .forms import ShippingForm
from .models import ShippingAddress, Order, OrderItem
from store.models import Profile
from django.contrib import messages
import datetime

# ----------------- for payment process -----------------
import hmac
import uuid
import hashlib
import base64
from decimal import Decimal, ROUND_HALF_UP


# ----------khalti payment---
import requests
import json


# Create your views here.
def payment_success(request):
    return render(request, 'payment-success.html')

def checkout(request):
    cart = Cart(request)    # get cart object
    cart_products = cart.get_products()
    quantities = cart.get_quantities()
    totals = cart.cart_total()
    
    if request.user.is_authenticated:
        shipping_user = ShippingAddress.objects.get(user__id = request.user.id)
        shipping_form = ShippingForm(request.POST or None, instance=shipping_user)
    else:
        # checkout as guest
        shipping_form = ShippingForm(request.POST or None)
    return render(request, 'checkout.html', {
        'cart_products': cart_products,
        'quantities' : quantities,
        'totals': totals,
        'shipping_form': shipping_form
    })


def esewa_payment(request):

    order_bill = make_billing(request)

    # ----------Integrating Esewa-----------------------#            
    #  edit to sth like today date e.ge sep-15 ..... or product_name, order_id
    transaction_uuid = f'apple-15-{str(uuid.uuid4())[:5]}'
    
    # ------------provided by esewa for development
    secret_key = b'8gBm/:&EnhH.1/q'     # must be byte
    product_code = 'EPAYTEST'            


    # total_amount=100,transaction_uuid=11-201-13,product_code=EPAYTEST (should be in same order)
    message = f'total_amount={order_bill['total_amount']},transaction_uuid={transaction_uuid},product_code={product_code}'          
    # Encode it as bytes (UTF-8)
    message_bytes = message.encode('utf-8')

    hmac_sha256 = hmac.new(secret_key, message_bytes, hashlib.sha256)
    digest = hmac_sha256.digest()
    signature = base64.b64encode(digest).decode('utf-8')


    # all required data for esewa transaction
    esewa_data = order_bill.copy()
    
    esewa_data['transaction_uuid'] = transaction_uuid
    esewa_data['signature'] = signature
    
    return esewa_data


def verify_esewa_payment(request):
    if request.GET.get('data'):
        base64_response = request.GET.get('data')
        decoded_bytes = base64.b64decode(base64_response)
        decoded_msg = decoded_bytes.decode('utf-8')
        json_msg = json.loads(decoded_msg)

        if json_msg['status'] == 'COMPLETE':
            messages.success(request, 'Payment Successful')
            # proceed further
            process_order(request, json_msg['total_amount'])       
            return redirect('payment-success')
    else:
        messages.error(request, "Esewa Payment Verification Failed.")
        return redirect('checkout')


def get_khalti_payment_url(request, total_amount):
    url = "https://dev.khalti.com/api/v2/epayment/initiate/"

    payload = json.dumps({
        "return_url": "http://localhost:8000/payment/khalti_status/",
        "website_url": "https://example.com/",
        "amount": total_amount,
        "purchase_order_id": "Order01",
        "purchase_order_name": "test",
        "customer_info": {
        "name": "Ram Bahadur",
        "email": "test@khalti.com",
        "phone": "9800000001"
        }
    })

    headers = {
        'Authorization': 'key live_secret_key_68791341fdd94846a146f0457ff7b455',
        'Content-Type': 'application/json',
    }

    response = requests.request("POST", url, headers=headers, data=payload)
    json_response = json.loads(response.text)
    print('\nreturning json_response from get_khalti_payment_url function')       
    return json_response



def khalti_payment(request, total_amount):       
    json_response = get_khalti_payment_url(request, total_amount)   
    payment_url = json_response['payment_url']
    print('\n redirecting to khalti payment url: ', payment_url)       
    return redirect(payment_url)

def verify_khalti_payment(request):        
    if request.GET.get('status') == 'Completed':     # from khalti payment
        messages.success(request, 'Payment Successful')
        process_order(request, request.GET.get('total_amount'))   # proceed further

        return redirect('payment-success')
    else:
        messages.error(request, "Khalti Payment Verification Failed.")
        return redirect('checkout')
            
    
def billing_info(request):
    if request.POST:
        cart = Cart(request)    # get cart object
        cart_products = cart.get_products()
        quantities = cart.get_quantities()
        totals = cart.cart_total()
        
        shipping_info = request.POST

        # ------------Updating default user ShippingAddress----
        ''' this is not recommended to change user default shipping address. instead use this for current order only
        shipping_instance = ShippingAddress.objects.get(user=request.user)

        shipping_form = ShippingForm(request.POST, instance=shipping_instance)  # loads exiting ShippingAddress (model prevent form creating new)
        if shipping_form.is_valid():
            shipping_address = shipping_form.save(commit=False)     # creates instance but doesn't save yet
            if request.user.is_authenticated:
                shipping_address.user = request.user
            shipping_address.save()     # saves or update the model      
        '''  

        # create a session with Shipped info
        request.session['my_shipping'] = shipping_info

        order_bill = make_billing(request)
        
        return render(request, 'billing-info.html', {
            'cart_products': cart_products,
            'quantities' : quantities,
            'totals': totals,
            'shipping_info': shipping_info,
            # 'billing_form':billing_form,
            # 'esewa_data' : new_esewa_data,      # no need
            # 'khalti_amount': khalti_amount  # no neeed
            'order_bill' : order_bill
        })
    else:   # must be post request
        messages.error(request, "Access Denied.")
        return redirect('checkout')
    
def make_billing(request):
    cart = Cart(request)
    totals = cart.cart_total()

    # for accounting & billing decimal is more preferred as float is risky (decimal is exact)       
    # round to 2 decimal places & round up only if >= 5     
    tax_amount = (totals * Decimal('0.13')).quantize(Decimal('0.01'), rounding=ROUND_HALF_UP)       # 13% vat                                    
    product_service_charge = 10
    product_delivery_charge= 1000
    total_amount_vat_inc = (totals + tax_amount + product_service_charge + product_delivery_charge).quantize(Decimal('0.01'), rounding=ROUND_HALF_UP)

    order_bill = {
        'amount': totals,
        'tax_amount': tax_amount,
        'psc': product_service_charge,
        'pdc': product_delivery_charge,                
        'total_amount': total_amount_vat_inc,
    } 
    return order_bill



def place_order(request):
    if request.method != 'POST':
        messages.error(request, "Access Denied.")
        return redirect('checkout')

    order_bill = make_billing(request)

    payment_method = request.POST.get('payment_method')
    if payment_method == 'cash':
        # process cash on delivery order payment on delivery
        pass
    elif payment_method == 'esewa':
        esewa_data = esewa_payment(request)
        return render(request, 'esewa-payment.html', { 'esewa_data': esewa_data })
    elif payment_method == 'khalti': 
        print('\n\nkhalti payment selected')   
        return khalti_payment(request, int(order_bill['total_amount'] * 100))  # khalti takes value in paisa
    
    messages.error(request, "Invalid Payment Method.")
    return redirect('checkout')
    


def process_order(request, total_amount):       # future change: add more validation    
    cart = Cart(request)    # get cart object
    cart_products = cart.get_products()
    quantities = cart.get_quantities()
    # totals = cart.cart_total()
    
    # Get shiping info from session
    my_shipping = request.session.get('my_shipping')
    if not my_shipping:
        messages.error(request, "Shipping Information Missing.")
        return redirect('checkout')
    
    # Gather order info
    full_name = my_shipping['shipping_full_name']
    email = my_shipping['shipping_email']

    # create shipping address from session data
    shipping_address = f"{my_shipping['shipping_address1']} \n{my_shipping['shipping_address2']} \n{my_shipping['shipping_city']} \n{my_shipping['shipping_zipcode']} \n{my_shipping['shipping_country']}"

    # -------------- reduced code -----------------
    create_order = Order(user=request.user if request.user.is_authenticated else None, 
                            full_name=full_name, email=email, shipping_address=shipping_address, amount_paid=total_amount)
    create_order.save()

    # Add order items
    for product in cart_products:
        # Get Quantity  {'3': 5, '1': 3}}
        for product_key, quantity in quantities.items():
            if int(product_key)  == product.id:
                price = product.sale_price if product.is_sale else product.price
                # create order item
                create_order_item = OrderItem(order = create_order,
                                                product = product,
                                                user= request.user if request.user.is_authenticated else None,
                                                quantity = quantity, price = price)
                create_order_item.save()

        # delete the cart after order & order_item are created
        '''
        for key in list(request.session.keys()):
            if key == "session_key":
                del request.session[key]
        '''

        # clear session
        request.session.pop('session_key', None)

        # delete the cart form db also
        current_user = Profile.objects.filter(user__id = request.user.id)
        # Delete shopping cart in db(old_cart field)
        current_user.update(old_cart = '')

        cart.clear()    # clear the cart session
        


def not_shipped_dash(request):
    if request.user.is_authenticated and request.user.is_superuser: # logged in as admin
        unshipped_orders = Order.objects.filter(shipped = False)
        if request.POST:
            order_id = request.POST['num']
            order = Order.objects.filter(id = order_id)
            
            now = datetime.datetime.now()
            # update as shipped  (no need to check status)
            order.update(shipped=True, date_shipped=now)
            
            messages.success(request, 'Shipping Status Updated')
            return redirect('home')   
        else:
            return render(request, 'not-shipped-dash.html', {
                'unshipped_orders' : unshipped_orders
            })
    else:
        messages.error(request, 'Access Denied')
        return redirect('home')

def shipped_dash(request):
    if request.user.is_authenticated and request.user.is_superuser: # logged in as admin
        shipped_orders = Order.objects.filter(shipped = True)

        if request.POST:
            order_id = request.POST['num']
            order = Order.objects.filter(id = order_id)
            
            order.update(shipped=False)
            
            messages.success(request, 'Shipping Status Updated')
            return redirect('home')   
        else:
            return render(request, 'shipped-dash.html', {
                'shipped_orders' : shipped_orders
            })
    else:
        messages.error(request, 'Access Denied')
        return redirect('home')


def orders(request, pk):
    if request.user.is_authenticated and request.user.is_superuser:
        order = Order.objects.get(id = pk)        
        # get the order items
        items = OrderItem.objects.filter(order=order)

        if request.POST:
            order = Order.objects.filter(id = pk)
            status = request.POST['shipping_status']
            if status == 'true':                
                # order.shipped = True    # only work for single object
                # order.save()
                now = datetime.datetime.now()
                order.update(shipped=True, date_shipped=now)  # QuerySet method
                
            else:
                order.update(shipped=False)
            
            messages.success(request, 'Shipping Status Updated')
            return redirect('home')
        return render(request, 'orders.html', {
            'order':order,
            'items':items
        })
    else:
        messages.error(request, 'Access Denied')
        return redirect('home')


