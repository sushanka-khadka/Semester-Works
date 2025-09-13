from django.contrib import admin
from django.contrib.auth.models import User 
from .models import Category, Customer, Product, Order, Profile
from django.contrib.auth.admin import UserAdmin as DefaultUserAdmin

# Register your models here.
admin.site.register(Category)
admin.site.register(Customer)
admin.site.register(Product)
admin.site.register(Order)
admin.site.register(Profile)

# mix Profile info and User Infor
class ProfileInline(admin.StackedInline):
    model = Profile

# extend User model
class CustomUserAdmin(DefaultUserAdmin):
    model = User
    # fields = ['username', 'first_name', 'last_name', 'email']
    inlines = [ProfileInline]

try:
    admin.site.unregister(User)
except admin.sites.NotRegistered:
    pass

# re-register new way
admin.site.register(User, CustomUserAdmin)
    