from django.urls import path
from . import views
from django.conf import settings
from django.conf.urls.static import static


urlpatterns = [
    path('', views.home, name='home'),
    path('about', views.about, name='about'),
    path('login', views.login_user, name='login'),
    path('logout', views.logout_user, name='logout'),
    path('register', views.register_user, name='register'),
    path('update_user', views.update_user, name='update-user'),
    path('update_info', views.update_info, name='update-info'),
    path('change_password', views.change_password, name='change-password'),
    path('reset_password', views.reset_password, name='reset-password'),
    path('product/<int:product_key>', views.product_details, name='product'), 
    path('category/<str:category_item>', views.category, name='category'), 
    path('category_summary/', views.category_summary, name='category-summary'), 
    path('search', views.search, name='search'),
]

urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)