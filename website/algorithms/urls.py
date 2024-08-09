from django.urls import path
from . import views

urlpatterns = [
    path('gui/', views.algorithms, name='gui'),
    # path('gui/', views.home, name='home'),
    path('', views.homePage, name='home'),
]
