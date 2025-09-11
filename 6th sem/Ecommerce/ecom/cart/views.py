from django.shortcuts import render, get_object_or_404, HttpResponse
from .cart import Cart
from store.models import Product
from django.http import JsonResponse

# Create your views here.
def cart_summary(request):
    cart = Cart(request)    # get cart object
    cart_products = cart.get_products()
    
    return render(request, 'cart_summary.html', {
        'cart_products': cart_products
    })

def cart_add(request):
    cart = Cart(request)
    # json response
    if request.POST.get('action') == 'post':
        product_id = int(request.POST.get('product_id'))
        # lookup products in DB
        product = get_object_or_404(Product, id=product_id) #  Fetches the corresponding product object from the database.
        # save to the session
        cart.add(product= product)
        # return response
        response = JsonResponse({'Product name':product.name})
        return response
    

def cart_delete(request):
    return None

def cart_update(request):
    return None