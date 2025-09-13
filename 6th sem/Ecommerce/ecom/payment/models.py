from django.db import models
from django.contrib.auth.models import User

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