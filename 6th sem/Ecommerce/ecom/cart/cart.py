from store.models import Product

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


    def add(self, product, quantity):
        product_id = str(product.id)
        product_qty = quantity
        if product_id in self.cart:
            pass
        else:   # add product under key, storing its price
            # self.cart[product_id] = {'price' : str(product.price)}
            self.cart[product_id] =  int(product_qty)

        self.session.modified =  True
    

    def __len__(self):      # dunder method to display no of items in cart
        return len(self.cart)
    
    
    def get_products(self):
        # get ids from cart
        product_ids = self.cart.keys()
        print(product_ids)
        products = Product.objects.filter(id__in = product_ids)

        # return those looked up products
        return products

