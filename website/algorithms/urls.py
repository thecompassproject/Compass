from django.urls import path
from . import views

urlpatterns = [
    path('gui/', views.algorithms, name='gui'),
    path('', views.homePage, name='home')
]
