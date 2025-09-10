class Cart():
    def __init__(self, request):
        self.session = request.session

        # get the current session key if it exists
        cart = self.session.get('session_key')

        # if user is new create one!
        if 'session_key' not in request.session:
            cart = cart.session['session_key']  = {}
        
        # cart should be available on all pages of site
        self.cart = cart