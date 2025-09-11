from django.urls import path
from . import views


urlpatterns = [
    path('', views.cart_summary, name='cart-summary'),
    path('add/', views.cart_add, name='add-cart'),
    path('delete/', views.cart_delete, name='delete-cart'),
    path('update/', views.cart_update, name='update-cart')
]