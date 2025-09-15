from django.contrib import admin
from .models import ShippingAddress, Order, OrderItem

# Register your models here.
admin.site.register(ShippingAddress)
admin.site.register(Order)
admin.site.register(OrderItem)

# OrderItem Inline
class OrderItemInline(admin.StackedInline):
    model = OrderItem
    extra = 0   # no empty forms by default

# Extend Order Model
class OrderAdmin(admin.ModelAdmin):
    model = Order
    fields = ['user', 'full_name', 'email', 'shipping_address', 'amount_paid', 'date_ordered', 'shipped', 'date_shipped']
    readonly_fields = ['date_ordered']
    inlines = [OrderItemInline]

# unregister old Order Model
admin.site.unregister(Order)

# reregister Order and OrderItem
admin.site.register(Order, OrderAdmin)