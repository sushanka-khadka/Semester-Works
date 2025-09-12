from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm, UserChangeForm
from django import forms

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