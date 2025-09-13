from django.db import models
from django.contrib.auth.models import User
from store.models import Product

# Create your models here.
# --------- Payment and Shipping
class ShippingAddress(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, null=True)
    shipping_full_name = models.CharField(max_length=100)
    shipping_email = models.EmailField(blank=False)
    shipping_address1= models.CharField(max_length=200)    
    shipping_address2= models.CharField(max_length=200, blank=True, null=True)
    shipping_city = models.CharField(max_length=100, blank=True)
    shipping_state = models.CharField(max_length=100, blank=True)
    shipping_zipcode = models.CharField(max_length=100, blank=True)
    shipping_country = models.CharField(max_length=100, blank=True)

    # don't pluralize address
    class Meta:
        verbose_name_plural = 'Shipping Address'

    def __str__(self):
        return f'Shipping Address - {str(self.id)}'
    

# create Order Model
class Order(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    full_name = models.CharField(max_length=100)
    email = models.EmailField()
    shipping_address = models.CharField(max_length=200)
    amount_paid = models.DecimalField(max_digits=8, decimal_places=2)
    date_ordered = models.DateTimeField(auto_now_add=True)  # never updates (one time set)

    def __str__(self):
        return f'Order - {str(self.id)}'

class OrderItem(models.Model):
    order = models.ForeignKey(Order, on_delete=models.CASCADE)
    product = models.ForeignKey(Product, on_delete=models.CASCADE)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    quantity = models.PositiveIntegerField(default=1)
    price = models.DecimalField(max_digits=8, decimal_places=2)

    def __str__(self):
        return f'Order Item - {str(self.id)}'