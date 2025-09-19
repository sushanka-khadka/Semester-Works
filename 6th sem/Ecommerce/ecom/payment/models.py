from django.db import models
from django.contrib.auth.models import User
from store.models import Product
from django.db.models.signals import post_save, pre_save
from django.dispatch import receiver
import datetime

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
    

# create a User Shipping Profile by default when user signs up
def create_shipping(sender, instance, created, **kwargs):
    if created:
        user_shipping = ShippingAddress(user=instance)
        user_shipping.save()

# automate the shipping address
post_save.connect(create_shipping, sender=User)


# create Order Model
class Order(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, null=True, blank=True)
    full_name = models.CharField(max_length=100)
    email = models.EmailField()
    shipping_address = models.CharField(max_length=200)
    amount_paid = models.DecimalField(max_digits=8, decimal_places=2)
    date_ordered = models.DateTimeField(auto_now_add=True)  # never updates (one time set)
    shipped = models.BooleanField(default=False)
    date_shipped = models.DateTimeField(blank=True, null=True)

    def __str__(self):
        return f'Order - {str(self.id)}'
    

# Auto add shipping date
@receiver(pre_save, sender = Order)     # registers the func as a pre-save signal receiver for the Order model. & pre_save → runs before Django saves an object to the database.
def set_shipped_date_on_update(sender, instance, **kwargs):
    if instance.pk:     # id of object about to be saved.
        now = datetime.datetime.now()
        obj = sender._default_manager.get(pk=instance.pk)       # current version of the object from the database.
        if instance.shipped and not obj.shipped:
            instance.date_shipped = now


class OrderItem(models.Model):
    order = models.ForeignKey(Order, on_delete=models.CASCADE)
    product = models.ForeignKey(Product, on_delete=models.CASCADE)
    user = models.ForeignKey(User, on_delete=models.CASCADE, null=True, blank=True)
    quantity = models.PositiveIntegerField(default=1)
    price = models.DecimalField(max_digits=8, decimal_places=2)

    def __str__(self):
        return f'Order Item - {str(self.id)}'