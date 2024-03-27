# Generated by Django 5.0.2 on 2024-03-21 19:14

import django.db.models.deletion
from django.conf import settings
from django.conf import settings
from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Player',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('last_login', models.DateTimeField(blank=True, null=True, verbose_name='last login')),
                ('username', models.CharField(null=True, unique=True)),
                ('battleTag', models.CharField(null=True, unique=True)),
                ('email', models.CharField(null=True, unique=True)),
                ('password', models.CharField(null=True)),
                ('is_active', models.BooleanField(default=True)),
                ('date_joined', models.DateTimeField(auto_now_add=True, null=True)),
                ('profile42_URL', models.CharField(null=True)),
                ('avatar', models.ImageField(blank=True, null=True, upload_to='images/')),
                ('is_online', models.IntegerField(default=0)),
                ('friends', models.JSONField(default=dict)),
            ],
            options={
                'abstract': False,
            },
        ),
        migrations.CreateModel(
            name='PlayerStats',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('rank', models.IntegerField(blank=True, null=True)),
                ('wins', models.IntegerField(default=0.0)),
                ('losses', models.IntegerField(default=0.0)),
                ('winrate', models.FloatField(default=0.0)),
                ('total_games', models.IntegerField(default=0.0)),
                ('total_points', models.IntegerField(default=0.0)),
                ('total_hits', models.IntegerField(default=0.0)),
                ('player', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]