from django import forms
from .models import User, ShippingAddress


class ShippingForm(forms.ModelForm):
    shipping_full_name= forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Full Name'}))
    shipping_email = forms.EmailField(label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Email Address'}))
    shipping_address1= forms.CharField(max_length=200, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Address 1'}))
    shipping_address2= forms.CharField(max_length=200, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Address 2'}), required=False)
    shipping_city = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'City'}), required=False)
    shipping_state = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'State'}), required=False)
    shipping_zipcode = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Zip Code'}), required=False)
    shipping_country = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Country'}), required=False)

    class Meta:
        model = ShippingAddress
        exclude = ['user'] 
