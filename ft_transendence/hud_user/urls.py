from django.urls import path
from hud_user.views import index, Register, Login, Logout, ConvertCodeToToken, DeleteAccount
from hud_user.views import Profile, Setting, UpdateInfo, Dashboard, globalStatistics
from hud_user.views import FriendsList, AddFriend
from hud_user.views import Game
from . import views
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [
    #All pages
    path('', index, name='index'),
    path('profile/', Profile, name='profile'),

    #Settings
    path('setting/', Setting, name='setting'),
    path('update-info/', UpdateInfo, name='update-info'),

    #Dashboard
    path('dashboard/', Dashboard, name='dashboard'),
    path('global-stats/', globalStatistics, name='dashboard'),
    path('dashboard/detail-match/<int:game_id>/', views.detail_match, name='detail_match'),

    #Games
    path('game_menu/', Game, name='game'),

    #Friends List
    path('friends-list/', FriendsList, name="friends-list"),
    path('addFriend/', AddFriend, name="add-friend"),

    #Authentication
    path('register/', Register, name='register'),
    path('login/', Login, name='login'),
    path('logout/', Logout, name='logout'),
    path('api/callback/', ConvertCodeToToken.as_view(), name='convert_token'),

    #Delete account
    path('delete-account/', DeleteAccount, name='delAccount'),

]+ static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
