class Cart():
    def __init__(self, request):    #  Connects the cart to the user’s request.session.
        self.session = request.session      #  attach the user's session to this cart object

        # get the current session key if it exists
        cart = self.session.get('session_key')

        # if user is new create cart!
        if 'session_key' not in request.session:
            cart = self.session['session_key']  = {}
        
        # cart should be available on all pages of site
        self.cart = cart        # Stores the result in self.cart, so all cart operations happen on this dictionary.

    def add(self, product):
        product_id = str(product.id)
        if product_id in self.cart:
            pass
        else:   # add product under key, storing its price
            self.cart[product_id] = {'price' : str(product.price)}

            self.session.modified =  True
