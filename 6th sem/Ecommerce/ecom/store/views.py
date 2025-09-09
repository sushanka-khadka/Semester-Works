from django.shortcuts import render, redirect
from .models import Product
from django.http import HttpResponse
from django.contrib.auth import authenticate, login, logout
from django.contrib import messages
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm
from django import forms

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
    return render(request, 'register.html')