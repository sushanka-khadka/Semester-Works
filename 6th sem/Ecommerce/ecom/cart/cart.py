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
    

    def cart_total(self):
        product_ids = self.cart.keys()  # collect the product ids from the cart
        products = Product.objects.filter(id__in = product_ids)    # lookup to products
        total = 0       
        for product_id, quantity in self.cart.items():        # dict {'1': 4}
            product_id = int(product_id)
            for product in products:
                if product.id == product_id:
                    if product.is_sale:
                        total = total + (product.sale_price * quantity)
                    else:
                        total = total + (product.price * quantity)            
        return total



    def __len__(self):      # dunder method to display no of items in cart
        return len(self.cart)
    
    
    def get_products(self):
        # get ids from cart
        product_ids = self.cart.keys()
        print(product_ids)
        products = Product.objects.filter(id__in = product_ids)

        # return those looked up products
        return products
    
    def get_quantities(self): 
        quants = self.cart
        return quants   #  {'3': 5, '1': 3}}
    

    def update(self, product, quantity):
        product_id = str(product.id)
        product_qty = int(quantity)

        self.cart[product_id] = product_qty
        self.session.modified = True
        
        
    def delete(self, product):
        product_id = str(product.id)
        
        print('getting to cart.py delete')
        print(product_id)
        print(self.cart)
        # delete from cart dictionary
        if product_id in self.cart:
            print('data is in self.cart')
            del self.cart[product_id]
        
        self.session.modified = True
        # return self.cart


