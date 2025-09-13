from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm, UserChangeForm, PasswordChangeForm, SetPasswordForm
from django import forms
from django.core.exceptions import ValidationError
from django.contrib.auth import password_validation
from django.core.validators import RegexValidator
from .models import Profile


class SignUpForm(UserCreationForm):
    email = forms.EmailField(label='', widget=forms.EmailInput(attrs={'class':'form-control', 'placeholder':'Email Address'}))
    first_name = forms.CharField(label='', max_length=100, widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'First Name' }))
    last_name = forms.CharField(label='', max_length=100, widget=forms.TextInput(attrs={'class':'form-control', 'placeholder': 'Last Name' }))

    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name', 'email', 'password1', 'password2']
    
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.fields['username'].widget.attrs['class'] = 'form-control'
        self.fields['username'].widget.attrs['placeholder'] = 'User Name'
        self.fields['username'].label = ''
        self.fields['username'].help_text = '<span class="form-text text-muted"><small>Required. 150 characters or fewer. Letters, digits and  digits and @/./+/-/_ only.</small></span>'

        for field in ['password1', 'password2']:
            self.fields[field].widget.attrs.update({
                'class':'form-control',
                'placeholder': 'Password' if field == 'password1' else 'Confirm Password',
                'minlength':8
            })
            self.fields[field].label  = ''

        self.fields['password1'].help_text = '<ul class="form-text text-muted small">' \
            '<li>Your password can\'t be too similar to your other personal information.</li>' \
            '<li>Your password can\'t be commonly userd password.</li><li>Your password can\'t be entirely numeric.</li>' \
        '</ul>' 
        self.fields['password2'].help_text = '<span class="form-text text-muted small">Enter the same password as before, for verification.</small></span>' 


class UpdateUserForm(UserChangeForm):
    # hides password 
    password = None     # else show suggest for password change
    # get other fields
    email = forms.EmailField(label='', widget=forms.EmailInput(attrs={'class':'form-control', 'placeholder':'Email Address'}))
    first_name = forms.CharField(label='', max_length=100, widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'First Name' }))
    last_name = forms.CharField(label='', max_length=100, widget=forms.TextInput(attrs={'class':'form-control', 'placeholder': 'Last Name' }))

    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name', 'email']
    
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.fields['username'].widget.attrs['class'] = 'form-control'
        self.fields['username'].widget.attrs['placeholder'] = 'User Name'
        self.fields['username'].label = ''
        self.fields['username'].help_text = '<span class="form-text text-muted"><small>Required. 150 characters or fewer. Letters, digits and  digits and @/./+/-/_ only.</small></span>'        


class UserInfoForm(forms.ModelForm):
    phone = forms.CharField(max_length=10,
                            label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Phone'}),
                            validators=[RegexValidator(regex=r'^9[8,7]\d{8}$', message="Please enter valid nepali phone number.")])
    address1= forms.CharField(max_length=200, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Address 1'}))
    address2= forms.CharField(max_length=200, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Address 2'}), required=False)
    city = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'City'}), required=False)
    state = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'State'}), required=False)
    zipcode = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Zip Code'}), required=False)
    country = forms.CharField(max_length=100, label='', widget=forms.TextInput(attrs={'class':'form-control', 'placeholder':'Country'}), required=False)
    
    class Meta:
        model = Profile
        exclude = ['user', 'date_modified', 'old_cart']
        


class ChangePasswordForm(PasswordChangeForm):
    def clean_new_password2(self):
        # Get both new passwords
        password1 = self.cleaned_data.get("new_password1")
        password2 = self.cleaned_data.get("new_password2")

        # Default check: both must match
        if password1 and password2 and password1 != password2:
            raise ValidationError("The two password fields didn’t match.")

        # ✅ Enforce password validators (strength, length, etc.)
        password_validation.validate_password(password2, self.user)

        # ✅ Our custom check: old password ≠ new password
        old_password = self.cleaned_data.get("old_password")
        if old_password and password2 and old_password == password2:
            raise ValidationError("Your new password cannot be the same as the old password.")

        return password2
    

    def __init__(self, user, *args, **kwargs):
        super().__init__(user, *args, **kwargs)

        self.fields['old_password'].widget.attrs['class'] = 'form-control'
        self.fields['old_password'].widget.attrs['placeholder'] = 'Old Password'
        self.fields['old_password'].label = ''
        self.fields['old_password'].help_text = '<span class="form-text text-muted"><small>Enter your old password.</small></span>'
        
        for field in ['new_password1', 'new_password2']:
            self.fields[field].widget.attrs.update({
                'class':'form-control',
                'placeholder': 'New Password' if field == 'new_password1' else 'Confirm New Password',
                'minlength':8
            })
            self.fields[field].label  = ''

        self.fields['new_password1'].help_text = '<ul class="form-text text-muted small">' \
            '<li>Your password can\'t be too similar to your other personal information.</li>' \
            '<li>Your password can\'t be commonly userd password.</li><li>Your password can\'t be entirely numeric.</li>' \
        '</ul>' 
        self.fields['new_password2'].help_text = '<span class="form-text text-muted small">Enter the same password as before, for verification.</small></span>' 


class ResetPasswordForm(SetPasswordForm):
    username = forms.CharField(
        max_length=150, 
        required=True, 
        widget= forms.TextInput(attrs ={
            'class':'form-control',
            'placeholder':'User Name'
        }),
        label="",
        help_text='<span class="form-text text-muted"><small>Required. 150 characters or fewer. Letters, digits and  digits and @/./+/-/_ only.</small></span>'
    )

    field_order = ['username', 'new_password1', 'new_password2']

    def __init__(self, user, *args, **kwargs):
        super().__init__(user, *args, **kwargs)
        
        for field in ['new_password1', 'new_password2']:
            self.fields[field].widget.attrs.update({
                'class':'form-control',
                'placeholder': 'New Password' if field == 'new_password1' else 'Confirm New Password',
                'minlength':8
            })
            self.fields[field].label  = ''

        self.fields['new_password1'].help_text = '<ul class="form-text text-muted small">' \
            '<li>Your password can\'t be too similar to your other personal information.</li>' \
            '<li>Your password can\'t be commonly userd password.</li><li>Your password can\'t be entirely numeric.</li>' \
        '</ul>' 
        self.fields['new_password2'].help_text = '<span class="form-text text-muted small">Enter the same password as before, for verification.</small></span>' 
    
    
    def clean_new_password2(self):
        # Get both new passwords
        password1 = self.cleaned_data.get("new_password1")
        password2 = self.cleaned_data.get("new_password2")

        # Default check: both must match
        if password1 and password2 and password1 != password2:
            raise ValidationError("The two password fields didn’t match.")

        # ✅ Enforce password validators (strength, length, etc.)
        password_validation.validate_password(password2, self.user)

        # ✅ Our custom check: old password ≠ new password
        old_password = self.cleaned_data.get("old_password")
        if old_password and password2 and old_password == password2:
            raise ValidationError("Your new password cannot be the same as the old password.")

        return password2
    