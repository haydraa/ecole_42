from django.urls import path
from pong_game.views import pong_game, statsUpdate, update_score
from pong_game.views import tournament, addAlias, delTournament, startTournament, resultTour, startMatch, EndTournament

urlpatterns = [
    path('pong/', pong_game, name='pong_game'), 
    path('update_score/', update_score, name='update_score'),
    path('stats-update/', statsUpdate, name='stats_update'),
    path('tournament-lobby/', tournament, name='tournament'),
    path('tournament-add-alias/', addAlias, name='add_alias'),
    path('delTournament/', delTournament, name='delTournament'),
    path('start-tournament/', startTournament, name='startTournament'),
    path('start-match/', startMatch, name='startMatch'),
    path('result-match-tournament/', resultTour, name='resultTour'),
    path('end-of-tournament/', EndTournament, name='endTournament'),
]
