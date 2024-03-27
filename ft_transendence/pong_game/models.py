from typing import Any
from django.db import models
from django.db.models import JSONField
from itertools import combinations

# Create your models here.

class GamesPlayed(models.Model):
    player = models.ForeignKey('hud_user.Player', on_delete=models.CASCADE)
    foe = models.CharField(null=True)
    player_score = models.IntegerField(default=0.00)
    foe_score = models.IntegerField(default=0.00)
    date = models.DateField(null=True, auto_now_add=True)

    highest_ball_speed = models.FloatField(null=True, default=0.00)
    nb_of_bounce = models.IntegerField(null=True, default=0.00)
    longest_set = models.IntegerField(null=True, default=0.00)

    def __str__(self):
        return f'{self.player.username} {self.player_score} vs {self.foe_score} {self.foe}'

class Tournament(models.Model):
    players = JSONField(default=list)
    players_stats = JSONField(default=dict) # {playername : [point scored, point taken]}
    matches = JSONField(default=list)

    def generate_matches(self):
        players_list = self.players
        self.matches = list(combinations(players_list, 2))
        for p in players_list:
            self.players_stats[p] = [0, 0]
        self.save()

    def update_score(self, player1_score, player2_score):
        try:
            player1, player2 = self.matches[0][0], self.matches[0][1]
        except IndexError:
            # Handle the case where matchID is not a valid index
            return

        self.players_stats[player1][0] += player1_score
        self.players_stats[player1][1] += player2_score

        self.players_stats[player2][0] += player2_score
        self.players_stats[player2][1] += player1_score

        del self.matches[0]
        self.save()

    def __str__(self):
        return f'tournament : {self.matches}'