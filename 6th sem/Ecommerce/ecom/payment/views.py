from django.shortcuts import render, redirect
from cart.cart import Cart
from .forms import ShippingForm
from .models import ShippingAddress
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
        # check if user is logged in 
        if request.user.is_authenticated:
            return render(request, 'billing-info.html', {
                'cart_products': cart_products,
                'quantities' : quantities,
                'totals': totals,
                'shipping_info': shipping_info
            })
        else:
            return redirect('login')
    else:
        messages.error(request, "Access Denied.")
        return redirect('checkout')