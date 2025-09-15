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


class PaymentForm(forms.Form):
    card_name= forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Name On Card'}))
    card_number= forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Card Number'}))
    card_exp_date= forms.DateTimeField(label='', widget=forms.DateTimeInput(attrs={'class':'form-control', 'placeholder':'Expiration Date'}))    
    card_cvv_number=  forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'CVV Code'}))    
    address1= forms.CharField(max_length=200, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Billing Address 1'}))
    address2= forms.CharField(max_length=200, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Billing Address 2'}), required=False)
    city = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Billing City'}), required=False)
    state = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'billing State'}), required=False)
    zipcode = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Billing Zip Code'}), required=False)
    country = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Billing Country'}), required=False)

    

