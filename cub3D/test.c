#include <X11/Xlib.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

#include <math.h>

#define MAP_WIDTH 15
#define MAP_HEIGHT 10
#define TILE_SIZE 64
#define FOV_ANGLE 60.0

typedef struct s_player {
    double x;
    double y;
    double angle;
} t_player;

typedef struct s_game {
    void *mlx;
    void *win;
    t_player player;
    int map[MAP_HEIGHT][MAP_WIDTH];
} t_game;

void draw_rectangle(t_game *game, int x, int y, int color) {
    mlx_string_put(game->mlx, game->win, x, y, color, " ");
}

void draw_map(t_game *game) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            int tile = game->map[i][j];
            int x = j * TILE_SIZE;
            int y = i * TILE_SIZE;
            int color = (tile == 1) ? 0x00FF0000 : 0x00FFFFFF;
            draw_rectangle(game, x, y, color);
        }
    }
}

void draw_player(t_game *game) {
    int x = game->player.x * TILE_SIZE;
    int y = game->player.y * TILE_SIZE;
    draw_rectangle(game, x, y, 0x0000FF00);
}

void draw_ray(t_game *game, double ray_angle) {
    double stepSize = 0.1;
    double x = game->player.x;
    double y = game->player.y;

    while (game->map[(int)y][(int)x] == 0) {
        x += stepSize * cos(ray_angle);
        y += stepSize * sin(ray_angle);
    }

    int ray_x = x * TILE_SIZE;
    int ray_y = y * TILE_SIZE;
    mlx_line_put(game->mlx, game->win, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE, ray_x, ray_y, 0x00FFFF00);
}

int draw(t_game *game) {
    mlx_clear_window(game->mlx, game->win);
    draw_map(game);
    draw_player(game);

    double player_angle = game->player.angle * M_PI / 180.0;

    for (int i = 0; i < 256; i++) {
        double ray_angle = player_angle - FOV_ANGLE / 2 + (FOV_ANGLE / 256) * i;
        draw_ray(game, ray_angle);
    }
	return(0);
	
}

int key_press(int keycode, t_game *game) {
    // Handle key presses here (e.g., to change the player's angle or position)
    return 0;
}

int main() {
    t_game game;
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "Ray-Casting");
    game.player.x = 3.5;
    game.player.y = 3.5;
    game.player.angle = 90;

    // Initialize the map with 1s for walls and 0s for empty spaces
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            game.map[i][j] = (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) ? 1 : 0;
        }
    }

    mlx_hook(game.win, 2, 0, &key_press, &game);

    mlx_loop_hook(game.mlx, &draw, &game);
    mlx_loop(game.mlx);

	return 0;
}





