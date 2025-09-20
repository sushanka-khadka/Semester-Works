from cart.cart import Cart


# create context processor class so the cart can work on all pages of site
def cart(request):
    # return the default data from the cart
    return { 'cart': Cart(request) }