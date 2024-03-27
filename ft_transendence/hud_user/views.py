from django.shortcuts import render, redirect, get_object_or_404
from django.views import View
from django.http import JsonResponse, HttpResponseRedirect
from requests_oauthlib import OAuth2Session
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.decorators import login_required
from .decorator import anonymous_required
from django.db import IntegrityError
from django.contrib.auth import authenticate, login, logout
import json
from hud_user.models import Player, PlayerStats
from pong_game.models import GamesPlayed
from django.conf import settings

# Create your views here.
@csrf_exempt
def index(request):

    try:
        if request.user.is_authenticated:
            player = request.user
            player.is_online = 1
            player.save()
    except:
        print('not logged')
    return render(request, "others/index.html")

class ConvertCodeToToken(View):
    def get(self, request, *args, **kwargs):
        unauthorize = request.GET.get('error')
        if unauthorize:
            if unauthorize == "access_denied":
                return redirect('/')
        code = request.GET.get('code')
        if not code:
            return JsonResponse({'Error': 'Missing authorization code'}, status=400)

        client_id = settings.API_42_KEY
        client_secret = settings.API_42_SECRET_KEY
        redirect_uri = 'https://transandance.42.fr/api/callback'
        token_url = 'https://api.intra.42.fr/oauth/token'
        data = {
            'client_id': client_id,
            'client_secret': client_secret,
            'code': code,
            'redirect_uri': redirect_uri,
            'grant_type': 'authorization_code'
        }
        oauth = OAuth2Session(client_id, redirect_uri=redirect_uri)

        response = oauth.post(token_url, data=data)
        token = response.json()
        user_info_url = 'https://api.intra.42.fr/v2/me'
        headers = {'Authorization': f'Bearer {token["access_token"]}'}
        response = oauth.get(user_info_url, headers=headers)
        user_info = response.json()

        player, created = Player.objects.get_or_create(
            username=user_info['login'],
            defaults={
                'email': user_info['email'],
                'profile42_URL': user_info['image']['versions']['medium'],
                'battleTag': user_info['login'],
                'is_online':True
            }
        )
        if created:
            users = Player.objects.all()
            for u in users:
                u.update_user_stats()
            login(request, player)
            player.is_online=1
            print(player, 'registered with 42 account')
            return HttpResponseRedirect('https://transandance.42.fr/')
        else:
            if player.password is None:
                users = Player.objects.all()
                for u in users:
                    u.update_user_stats()
                login(request, player)
                player.is_online=True
                player.save()
                print(player, 'logged in with 42 account')
            return HttpResponseRedirect('https://transandance.42.fr/')

@csrf_exempt
@anonymous_required
def Register(request):
    if request.method == 'POST':
        print(f'Raw request body: {request}')
        if request.body:
            try:
                data = json.loads(request.body)
                print(f'Data received from POST : {data}')
            except json.JSONDecodeError:
                return JsonResponse({'error': 'Invalid JSON'}, status=400)
        else:
            return JsonResponse({'error': 'Request body is empty'}, status=400)
        if 'RegisterForm' in data :
            try:
                player = Player(username=data.get('username'),
                                battleTag=data.get('username'),
                                email=data.get('email'))
                player.set_password(data.get('password'))
                player.save()
                users = Player.objects.all()
                for u in users:
                    u.update_user_stats()
                player = authenticate(username=player.username, password=data.get('password'))
                if player is not None:
                    login(request, player)
                    player.is_online=1
                    player.save()
                    print(f'{player} is register and logged in')
                    return render(request, "others/index.html")
                else:
                    return JsonResponse({'error': 'Failed to login'})
            except IntegrityError:
                return JsonResponse({'error': 'Invalid register'})
        return JsonResponse({'error': 'Not a valid form'})
    else:
        return render(request, "auth/register.html")

@csrf_exempt
@anonymous_required
def Login(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        print(f'Data received from POST : {data}')
        if 'LoginForm' in data :
            try:
                print(f"username : {data.get('username')}, password : {data.get('password')}")
                player = authenticate(username=data.get('username'), password=data.get('password'))
                if player is None:
                    return JsonResponse({'error': 'Player not found'})
                login(request, player)
                player.is_online=1
                player.save()
                print(f'{player} is logged in')
                return render(request, "others/index.html")
            except IntegrityError:
                return JsonResponse({'error': 'Invalid login'})
        return JsonResponse({'error': 'Not a valid form'})
    else:
        return render(request, "auth/login.html")

@csrf_exempt
@login_required
def Logout(request):
    player = request.user
    player.is_online=0
    player.save()
    logout(request)
    return render(request, "others/index.html")

@csrf_exempt
@login_required
def Profile(request):
    try:
        player = request.user
        users = Player.objects.all()
        for user in users:
            user.update_user_stats()
        if player is not None:
            data = {
                "playerstats": PlayerStats.objects.get(player=player),
                "username": player.username,
                "battleTag": player.battleTag,
                "email": player.email,
                "date": player.date_joined.strftime('%d/%m/%Y'),
            }
            return render(request, 'others/profile.html', data)
        else:
            print("player is None")
            return redirect('')
    except Player.DoesNotExist:
        print("player does not exist")
        return render(request, 'others/profile.html', data)

@csrf_exempt
@login_required
def Dashboard(request):
    users = Player.objects.all()
    for user in users:
        user.update_user_stats()
    print(f'dashboard view{type(request.user)}')
    playerstats = PlayerStats.objects.get(player=request.user)
    print(f'{playerstats} here')
    gameplayed = GamesPlayed.objects.filter(player=request.user)
    gameplayed = gameplayed.order_by('-date')
    data = {
        "gameplayed": gameplayed,
        "playerstats": {
            "wins": playerstats.wins,
            "losses": playerstats.losses,
            "winrate": playerstats.winrate,
            "total_games": playerstats.total_games,
            "total_points": playerstats.total_points,
            "total_hits": playerstats.total_hits,
            "rank": playerstats.rank,
        },
    }
    return render(request, 'dashboard/dashboard.html', data)

@csrf_exempt
@login_required
def globalStatistics(request):
    users = Player.objects.all()
    for user in users:
        user.update_user_stats()
    playerstats = PlayerStats.objects.get(player=request.user)
    data = {
        "playerstats": {
            "wins": playerstats.wins,
            "losses": playerstats.losses,
            "winrate": playerstats.winrate,
            "total_games": playerstats.total_games,
            "total_points": playerstats.total_points,
            "total_hits": playerstats.total_hits,
            "rank": playerstats.rank,
        },
    }
    return render(request, 'dashboard/global_statistics.html', data)

@csrf_exempt
@login_required
def detail_match(request, game_id):
    game = get_object_or_404(GamesPlayed, id=game_id)
    return render(request, 'dashboard/detail_match.html', {'game': game})

@csrf_exempt
@login_required
def Game(request):
    player = request.user
    if player.tournament is not None:
        player.tournament.delete()
        player.tournament = None
        player.save()
    return render(request, 'game/game.html')

@csrf_exempt
@login_required
def Setting(request):
    is42 = False
    if request.user.profile42_URL:
        is42 = True
    return render(request, 'others/setting.html', {'is42': is42})

@csrf_exempt
@login_required
def UpdateInfo(request):
    if request.method == 'POST':
        if request.POST.get('formUpdateInfo'):
            try:
                username = request.POST.get('username')
                battleTag = request.POST.get('battleTag')
                password = request.POST.get('password')
                avatar = request.FILES.get('avatar')

                player = request.user
                if username:
                    player.username = username
                if battleTag:
                    player.battleTag = battleTag
                if password:
                    player.set_password(password)
                if avatar:
                        player.avatar.save(avatar.name, avatar, save=False)


                player.save()
                login(request, player)
                return JsonResponse({'success': 'info updated.'})
            except:
                return JsonResponse({'error': 'Invalid form info update.'})

@csrf_exempt
@login_required
def DeleteAccount(request):
    player = request.user
    logout(request)

    print(f'{player} has been deleted from friends list')
    players = Player.objects.all()
    for p in players:
        if player.username in p.friends:
            print(f'{player} has been deleted from friends list of {p}')
            del p.friends[player.username]
            p.save()

    print(f'{player} has been delete.')
    player.delete()
    return render(request, "others/index.html")

@csrf_exempt
@login_required
def FriendsList(request):
    player = request.user
    print(f'Friends list : {player.friends}')
    data = {}
    data["friends"] = None
    if bool(player.friends):
        data["friends"] = []
        for id in player.friends.values():
            print(f'{Player.objects.get(id=id).username} is {Player.objects.get(id=id).is_online}')
            friend = Player.objects.get(id=id)
            data["friends"].append(f'{friend.username} is {"offline" if friend.is_online == 0 else "online" if friend.is_online == 1 else "in game" if friend.is_online == 2 else "unknown"}')
    return render(request, "others/friends-list.html", data)
    
@csrf_exempt
@login_required
def AddFriend(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        if 'formAddFriend' in data:
            player = request.user
            try:
                friend = Player.objects.get(username=data.get('username'))
                # Modifier le dictionnaire 'friends' et le réaffecter à l'attribut 'friends'
                player.friends[data.get('username')] = friend.id
                player.save()
            except Player.DoesNotExist:
                return JsonResponse({'error': 'Player not found'})
    data = {}
    if bool(player.friends):
        data["message"] = None
        friends = []
        for id in player.friends.values():
            friends.append(f'{Player.objects.get(id=id)} is {"Online" if player.is_online else "Offline"}')
        data['friends'] = friends
    else:
        data["message"] = "You don't have friends..."
    return render(request, "others/friends-list.html", data)

 