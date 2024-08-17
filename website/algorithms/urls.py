from django.urls import path
from . import views

urlpatterns = [
    path('', views.homePage, name='home'),
    path('gui/', views.algorithms, name='gui'),
    path('codeblocks/', views.codeBlocks, name='codeblocks')
]
