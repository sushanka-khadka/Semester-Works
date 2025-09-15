from django.shortcuts import render, redirect
from cart.cart import Cart
from .forms import ShippingForm, PaymentForm
from .models import ShippingAddress, Order, OrderItem
from django.contrib.auth.models import User
from django.contrib import messages

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
        print(my_shipping)

        # gather order info
        full_name = my_shipping['shipping_full_name']
        email = my_shipping['shipping_email']
        
        # create shipping address from session data
        shipping_address = f"{my_shipping['shipping_address1']} \n{my_shipping['shipping_address2']} \n{my_shipping['shipping_city']} \n{my_shipping['shipping_zipcode']} \n{my_shipping['shipping_country']}"
        
        amount_paid = totals

        if request.user.is_authenticated:
            user = request.user
            # create order
            create_order = Order(user=user, full_name=full_name, email=email, shipping_address=shipping_address, amount_paid=amount_paid)
            create_order.save()

            # Add order items
            order_id = create_order.pk
            # Get product_info
            for product in cart_products:
                product_id = product.id
                if product.is_sale:
                    price = product.sale_price
                else:
                    price = product.price

                # Get Quantity  {'3': 5, '1': 3}}
                for product_key, quantity in quantities.items():
                    if int(product_key) == product_id:
                        # Create order item
                        create_order_item = OrderItem(order_id = order_id, product_id=product_id, user= user, quantity=quantity, price=price)
                        create_order_item.save()                       
            
            # delete the cart
            for key in list(request.session.keys()):
                if key == "session_key":
                    del request.session[key]
            
            messages.success(request, "Order Placed.")
            return redirect('home')
        else:   # not logged in
            create_order = Order(full_name=full_name, email=email, shipping_address=shipping_address, amount_paid=amount_paid)
            create_order.save()

            # Add order items
            order_id = create_order.pk
            # Get product_info
            for product in cart_products:
                product_id = product.id
                if product.is_sale:
                    price = product.sale_price
                else:
                    price = product.price

                # Get Quantity  {'3': 5, '1': 3}}
                for product_key, quantity in quantities.items():
                    if int(product_key) == product_id:
                        # Create order item
                        create_order_item = OrderItem(order_id = order_id, product_id=product_id, quantity=quantity, price=price)
                        create_order_item.save()
                        
            # delete the cart
            for key in list(request.session.keys()):
                if key == "session_key":
                    del request.session[key]

            messages.success(request, "Order Placed.")
            return redirect('home')
    else:
        messages.error(request, "Access Denied.")
        return redirect('home')