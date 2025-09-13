from django.shortcuts import render, redirect
from .models import Product, Category, Profile
from django.http import HttpResponse
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.models import User
from django.contrib import messages
from .forms import SignUpForm, UpdateUserForm, ChangePasswordForm, ResetPasswordForm, UserInfoForm
from django.db.models import Q

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
                messages.success(request, "Username created. Please fill out your info below!")
                return redirect('update-info')
        else:
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
        messages.error(request, 'You must be logged in to update profile.')
        return redirect('login')            
    
def update_info(request):
    if request.user.is_authenticated:
        current_user = Profile.objects.get(user__id = request.user.id)
        form = UserInfoForm(request.POST or None, instance=current_user)
        if form.is_valid():
            form.save()
            messages.success(request, 'Your information has been Updated...')
            return redirect('home')
        return render(request, 'update-info.html', { 'form' : form })
    else:
        messages.error(request, 'You must be logged in to update information.')
        return redirect('login')

def change_password(request):
    if request.user.is_authenticated:
        current_user = request.user

        form = ChangePasswordForm(current_user)
        if request.method == "POST":
            form = ChangePasswordForm(data= request.POST, user= current_user)
            print(form)
            if form.is_valid():
                form.save()
                login(request, current_user)
                messages.success(request, "Password Changed Successfully.")
                return redirect('home')
            else:
                for error in list(form.errors.values()):
                    messages.error(request, error)
                return render(request, 'change-password.html', {
                    'form' : form
                })
        else:
            return render(request, 'change-password.html', {
                'form' : form
            })
    else:
        messages.error(request, "Your need to be logged in first.")
        return redirect('login')
 

def reset_password(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('new_password2')
        try:
            user = User.objects.get(username= username)
        except User.DoesNotExist:
            form = ResetPasswordForm(user=None)
            messages.error(request, f"User \"{username}\" doesn't exist.")
            return redirect('reset-password')

        form = ResetPasswordForm(data=request.POST, user=user)
        if form.is_valid():     # advance : email or otp verification
            # if old and new password are same
            if authenticate(request=request, username=username, password=password):  # password is same as old passowrd
                messages.error(request, 'Please enter new password different than old password.')
                return render(request, 'reset-password.html', {'form':form})
            
            form.save() # sets new password 
            password = form.cleaned_data['new_password2']

            # authenticate and login
            user = authenticate(request=request, username=username, password=password)
            if user:
                login(request, user)
                messages.success(request, 'Password reset successful.')
                return redirect('home')
            else:
                messages.error(request, 'Password reset succeeded, but login failed.')
                return redirect('login')
        else:
            for error in form.errors.values():
                messages.error(request, error)
            return render(request, 'reset-password.html', {'form':form})                    
    else:
        form = ResetPasswordForm(user= None)        # GET method
        return render(request, 'reset-password.html', {'form':form})


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

def search(request):
    if request.method == 'POST':
        searched = request.POST.get('search_str')
        available_products = Product.objects.filter(Q(name__icontains = searched) | Q(description__icontains = searched))
        
        # available_products = Product.objects.filter(name__icontains = searched)
        return render(request, 'search.html', {
            'products' : available_products
        })
    return render(request, 'search.html')