from django.shortcuts import redirect, render
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.decorators import login_required
import json
from django.core.exceptions import ObjectDoesNotExist
from django.http import JsonResponse
from hud_user.models import Player, PlayerStats
from pong_game.models import GamesPlayed, Tournament
# Create your views here.


@csrf_exempt
@login_required
def update_score(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        player = request.user
        new_score = data.get('score')

        # Assuming you have a Player model with a username field
        player_stats = PlayerStats.objects.get(player=player)

        player_stats.score = new_score
        player_stats.save()
        return JsonResponse({'status': 'success', 'message': 'Score updated'})
    else:
        return JsonResponse({'status': 'error', 'message': 'Invalid request method'})

@csrf_exempt
@login_required
def statsUpdate(request):
    try:
        data = json.loads(request.body)
        player = request.user
        player_stats = PlayerStats.objects.get(player=player)
        player_stats.total_hits += data.get('foe_score')
        player_stats.total_points += data.get('player_score')
        print(data)
        game = GamesPlayed(player=player,
                        foe=data.get('foe_name'),
                        player_score=data.get('player_score'),
                        foe_score=data.get('foe_score'),
                        highest_ball_speed=data.get('highest_ball_speed'),
                        nb_of_bounce=data.get('nb_of_bounce'),
                        longest_set=data.get('longest_set'),

                        )
        print("Pong game created")
        players = PlayerStats.objects.all()
        game.save()
        for p in players:
            p.update_user_stats()
            player_stats.save()
        print("Pong game saved")
        print(data)
        return JsonResponse({'status': 'success'})
    except:
        return JsonResponse({'status': 'failure'})

@csrf_exempt
@login_required
def pong_game(request):
    player = request.user
    player.is_online = 2
    player.save()
    data = {'player': player.username}
    return render(request, 'game/pong_solo/pong_solo.html', data)

@csrf_exempt
@login_required
def tournament(request):
    player = request.user
    data = {'player': player.battleTag}
    data["alias"] = None

    # Check if the player is associated with a tournament
    if player.tournament is None:
        # If not, create a new tournament and associate it with the player
        tournament = Tournament.objects.create()
        player.tournament = tournament
        player.save()

    if bool(player.tournament.players):
        data['alias'] = []
        for alias in player.tournament.players:
            data["alias"].append(alias)
    print(f' players : {player.tournament.players}')
    return render(request, "game/tournament/tournament_lobby.html", data)

@csrf_exempt
@login_required
def addAlias(request):
    player = request.user

    # Check if the player is associated with a tournament
    if player.tournament is None:
        # If not, create a new tournament and associate it with the player
        tournament = Tournament.objects.create()
        player.tournament = tournament
        player.save()

    if request.method == 'POST':
        data = json.loads(request.body)
        if data.get('alias') not in player.tournament.players and  data.get('alias') is not player.battleTag:
            player.tournament.players.append(data.get('alias'))
            player.tournament.save()
    data = {'player': player.battleTag}
    data["alias"] = None

    if bool(player.tournament.players):
        data['alias'] = []
        for alias in player.tournament.players:
            data["alias"].append(alias)
    print(f' players : {player.tournament.players}')
    return render(request, "game/tournament/tournament_lobby.html", data)

@csrf_exempt
@login_required
def delTournament(request):
    player = request.user
    if player.tournament is None or player.username not in player.tournament.players:
        return render(request, 'game.html')
    player.tournament.delete()
    player.tournament = None
    player.save()
    return render(request, 'game/game.html')

@csrf_exempt
@login_required
def startTournament(request):
    player = request.user
    player.is_online = 2
    player.save()
    if player.tournament is None or len(player.tournament.players) < 1:
        return redirect('tournament')
        # return JsonResponse({'error': 'you cant start without creating a tournament'})
    if player.battleTag not in player.tournament.players:
        player.tournament.players.append(player.battleTag)
    player.tournament.generate_matches()
    print(f'matches at start :{player.tournament}')
    data = {}
    data['last_round'] = True
    if len(player.tournament.matches) > 1:
        data['last_round'] = False
        data['nextPlayer1'] = player.tournament.matches[1][0]
        data['nextPlayer2'] = player.tournament.matches[1][1]
    data['player1'] = player.tournament.matches[0][0]
    data['player2'] = player.tournament.matches[0][1]
    return render(request, "game/tournament/between_matches.html", data)

@csrf_exempt
@login_required
def startMatch(request):
    player = request.user
    if player.tournament is None or player.username not in player.tournament.players:
        return redirect('tournament')
        # return JsonResponse({'error': 'you cant start without creating a tournament'})
    if len(player.tournament.matches) <= 0:
        #faire redirection resultat tournois
        return  JsonResponse({'redirect_url': '/game/end-of-tournament/'})
    data = {}
    data['last_round'] = True
    if len(player.tournament.matches) > 1:
        data['last_round'] = False
        data['nextPlayer1'] = player.tournament.matches[1][0]
        data['nextPlayer2'] = player.tournament.matches[1][1]
    data['player1'] = player.tournament.matches[0][0]
    data['player2'] = player.tournament.matches[0][1]
    return render(request, 'game/tournament/tournament_match.html', data)

@csrf_exempt
@login_required
def resultTour(request):
    player = request.user
    if player.tournament is None or player.username not in player.tournament.players:
        return redirect('tournament')
        # return JsonResponse({'error': 'you cant start without creating a tournament'})
    
    if request.method == 'POST':
        if not request.body:
            return JsonResponse({'error': 'No data provided'}, status=400)

        try:
            print(f' matches1 :{player.tournament.matches}')
            data = json.loads(request.body)
            player.tournament.update_score(data.get('player1_score'), data.get('player2_score'))
            player.save()
            print(f' matches2 :{player.tournament.matches}')
        except json.JSONDecodeError:
            return JsonResponse({'error': 'Invalid JSON'}, status=400)
    
    if len(player.tournament.matches) <= 0:
        #faire redirection resultat tournois
        return  JsonResponse({'redirect_url': '/game/end-of-tournament/'})
    data = {}
    data['last_round'] = True
    if len(player.tournament.matches) > 1:
        data['last_round'] = False
        data['nextPlayer1'] = player.tournament.matches[1][0]
        data['nextPlayer2'] = player.tournament.matches[1][1]
    data['player1'] = player.tournament.matches[0][0]
    data['player2'] = player.tournament.matches[0][1]

    return render(request, "game/tournament/between_matches.html", data)

@csrf_exempt
@login_required
def EndTournament(request):
    player = request.user
    if player.tournament is None or player.username not in player.tournament.players:
        redirect('tournament')
    sorted_player_stats = sorted(player.tournament.players_stats.items(), key=lambda item: item[1][0], reverse=True)
    
    # Separate keys (usernames) and values (stats)
    usernames = [item[0] for item in sorted_player_stats]
    stats = [item[1] for item in sorted_player_stats]
    
    # Combine usernames and stats into a single list of tuples
    combined_data = list(zip(usernames, stats))
    
    data = {
        'player': player.username,
        'combined_data': combined_data,
    }
    return render(request, 'game/tournament/end_of_tournament.html', data)
