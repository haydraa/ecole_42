from django.db import models
from django.db.models import F, Sum
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager
from django.db.models import JSONField
from django.apps import apps

# GamesPlayed = apps.get_model('pong_game', 'GamesPlayed')

class PlayerManager(BaseUserManager):
    def get_by_natural_key(self, username):
        return self.get(username=username)

# Create your models here.
class Player(AbstractBaseUser):
    username=models.CharField(null=True, unique=True)
    battleTag=models.CharField(null=True, unique=True)
    email=models.CharField(null=True, unique=True)
    password=models.CharField(null=True)
    is_active=models.BooleanField(default=True)
    date_joined=models.DateTimeField(null=True, auto_now_add=True)
    profile42_URL=models.CharField(null=True)
    avatar = models.ImageField(null=True, blank=True, upload_to='images/')

    tournament = models.ForeignKey('pong_game.Tournament', on_delete=models.CASCADE, null=True, blank=True)

    is_online=models.IntegerField(default=0)
    friends = JSONField(default=dict)

    USERNAME_FIELD = 'username'
    objects = PlayerManager()
    
    def __str__(self):
        return self.username

    @property
    def tournament_instance(self):
        Tournament = apps.get_model('pong_game', 'Tournament')
        return Tournament.objects.get(id=self.tournament_id)

    def update_user_stats(self):
        games = apps.get_model('pong_game', 'GamesPlayed').objects.filter(player=self)
        print(games)
        player_stats, created = PlayerStats.objects.get_or_create(player=self)
        player_stats.total_games = games.count()
        player_stats.total_points = games.aggregate(total_points=Sum('player_score'))['total_points']
        player_stats.total_hits = games.aggregate(total_hits=Sum('foe_score'))['total_hits']
        if player_stats.total_games == 0:
            return 0
        else:
            player_stats.wins = games.filter(player_score__gt=F('foe_score')).count()
            player_stats.losses = games.filter(player_score__lt=F('foe_score')).count()
            player_stats.winrate = round((player_stats.wins / (player_stats.wins + player_stats.losses)) * 100, 2)
            player_stats.rank = Player.objects.filter(playerstats__winrate__gt=player_stats.winrate).count() + 1
        player_stats.save()

class PlayerStats(models.Model):
    player = models.ForeignKey(Player, on_delete=models.CASCADE)
    rank = models.IntegerField(null=True, blank=True)
    wins = models.IntegerField(default=0.00)
    losses = models.IntegerField(default=0.00)
    winrate = models.FloatField(default=0.00)
    total_games = models.IntegerField(default=0.00)
    total_points = models.IntegerField(default=0.00)
    total_hits = models.IntegerField(default=0.00)

    def __str__(self):
        return self.player.username
