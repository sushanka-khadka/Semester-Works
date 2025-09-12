from django.shortcuts import render, redirect
from .models import Product, Category
from django.http import HttpResponse
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.models import User
from django.contrib import messages
from .forms import SignUpForm, UpdateUserForm

# Create your views here.
def home(request):
    products= Product.objects.all()
    return render(request, 'home.html', {
        'products': products
    })

def about(request):
    return render(request, 'about.html')

def login_user(request):
    if (request.method == 'POST'):
        username = request.POST.get('username')
        password = request.POST.get('password')
        print(username, password)
        user = authenticate(request, username=username, password=password)
        
        if user is not None:    # Check if authentication was successful - if user exists
            login(request, user)
            messages.success(request, "Logged in successfully!")
            return redirect('home')
        else:
            messages.error(request, "Invalid username or password.")
            return redirect('login')        
    return render(request, 'login.html')

def logout_user(request):
    logout(request=request)
    messages.success(request=request, message="Logout Successfully!!!")
    return redirect('home')

def register_user(request):
    form = SignUpForm()
    if request.method == 'POST':
        form = SignUpForm(request.POST)
        if form.is_valid():
            form.save()     # creates and saves the new user to the db
            username = form.cleaned_data['username']
            password = form.cleaned_data['password1']   # extract ceredentails from the form
            user = authenticate(request=request, username=username, password=password) # check if a user with that ceredentails exists if password is correct return user else none
            if user is not None:    # if user exixts
                login(request, user)        # automatically log in 
                messages.success(request, "Your registration is successful.")
                return redirect('home')
        else:
            print(form)
            print(form.cleaned_data)
            messages.error(request, "There was a problem registering the user.")
            return render(request, 'register.html', {'form': form})
    else:
        return render(request, 'register.html', {
            'form' : form
        })
    

def update_user(request):
    if request.user.is_authenticated:
        current_user = User.objects.get(id = request.user.id)
        # Handles GET and POST in the same form instance and pre-fills the form with the current user’s data.
        user_form = UpdateUserForm(request.POST or None, instance=current_user)     
        if user_form.is_valid() :
            user_form.save()        # updates the existing user instead of creating a new one.
            
            login(request, current_user)        # refreshes the session
            messages.success(request, 'User has been Updated...')
            return redirect('home')
        return render(request, 'update-user.html', {
            'user_form' : user_form
        })
    else:
        messages.error(request, 'You must be logged in to access this page.')
        return redirect('login')            


def product_details(request, product_key):
    product = Product.objects.get(id = product_key)
    return render(request, 'product.html', {
        'product':product
    })


def category(request, category_item):
    # replace Hypens with spaces
    category_item = category_item.replace('-', ' ')
    try:
        # grab the category form the url
        category = Category.objects.get(name=category_item)
        products = Product.objects.filter(category = category)
        
        return render(request, 'category.html', {
            'products':products,
            'category':category
        })
    except:
        messages.error(request, "That category doesn't exist.")
        return redirect('home')
    

def category_summary(request):
    categories = Category.objects.all()
    return render(request, 'category-summary.html', {
        'categories' : categories
    })