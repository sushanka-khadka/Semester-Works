from django.shortcuts import render, redirect
from cart.cart import Cart
from .forms import ShippingForm, PaymentForm
from .models import ShippingAddress, Order, OrderItem
from django.contrib.auth.models import User
from django.contrib import messages
import datetime

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


def billing_info(request):
    if request.POST:
        cart = Cart(request)    # get cart object
        cart_products = cart.get_products()
        quantities = cart.get_quantities()
        totals = cart.cart_total()
        
        shipping_info = request.POST

        # create a session with Shipped info
        request.session['my_shipping'] = shipping_info

        # check if user is logged in 
        if request.user.is_authenticated:
            # get the billing form
            billing_form = PaymentForm()
            return render(request, 'billing-info.html', {
                'cart_products': cart_products,
                'quantities' : quantities,
                'totals': totals,
                'shipping_info': shipping_info,
                'billing_form':billing_form
            })
        else:
            # not logged in
            billing_form = PaymentForm()
            return render(request, 'billing-info.html', {
                'cart_products': cart_products,
                'quantities' : quantities,
                'totals': totals,
                'shipping_info': shipping_info,
                'billing_form':billing_form
            })            
    else:
        messages.error(request, "Access Denied.")
        return redirect('checkout')
    

def process_order(request):
    if request.POST:     # if any form data from previous billing info
        cart = Cart(request)    # get cart object
        cart_products = cart.get_products()
        quantities = cart.get_quantities()
        totals = cart.cart_total()

        # get billing info from last page
        payment_form = PaymentForm(request.POST or None)        
        #  get shipping Session data
        my_shipping = request.session.get('my_shipping')
        # gather order info
        full_name = my_shipping['shipping_full_name']
        email = my_shipping['shipping_email']
        
        # create shipping address from session data
        shipping_address = f"{my_shipping['shipping_address1']} \n{my_shipping['shipping_address2']} \n{my_shipping['shipping_city']} \n{my_shipping['shipping_zipcode']} \n{my_shipping['shipping_country']}"
        
        # -----------------reduced code -----------------
        create_order = Order(user=request.user if request.user.is_authenticated else None, 
                             full_name=full_name, email=email, shipping_address=shipping_address, amount_paid=totals)
        create_order.save()

        # Add order items
        for product in cart_products:
            # Get Quantity  {'3': 5, '1': 3}}
            for product_key, quantity in quantities.items():
                if int(product_key) == product.id:
                    price = product.sale_price if product.is_sale else product.price
                    # Create order item
                    create_order_item = OrderItem(order = create_order, 
                                                  product = product, 
                                                  user= request.user if request.user.is_authenticated else None, 
                                                  quantity=quantity, price=price)
                    create_order_item.save()    
        
        # delete the cart after order & order_item are created
        for key in list(request.session.keys()):
            if key == "session_key":
                del request.session[key]

        messages.success(request, "Order Placed.")
        return redirect('home') 
    else:
        messages.error(request, "Access Denied.")
        return redirect('home')      
    

def not_shipped_dash(request):
    if request.user.is_authenticated and request.user.is_superuser: # logged in as admin
        unshipped_orders = Order.objects.filter(shipped = False)

        return render(request, 'not-shipped-dash.html', {
            'unshipped_orders' : unshipped_orders
        })
    else:
        messages.error(request, 'Access Denied')
        return redirect('home')

def shipped_dash(request):
    if request.user.is_authenticated and request.user.is_superuser: # logged in as admin
        shipped_orders = Order.objects.filter(shipped = True)

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
