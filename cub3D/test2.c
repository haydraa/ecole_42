#include <stdio.h>
#include <math.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define TILE_SIZE (WINDOW_WIDTH / MAP_WIDTH)

// Map representing the game world (1 = wall, 0 = empty space)
int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point start;
    Point direction;
} Ray;

typedef struct {
    void *mlx;
    void *win;
} MiniLibXData;

MiniLibXData mlx_data;

// Function to calculate the distance between two points
float distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Function to render a vertical line (column) on the screen
void draw_vertical_line(int x, int height) {
    for (int y = 0; y < WINDOW_HEIGHT; y++) {
        if (y < (WINDOW_HEIGHT - height) / 2 || y >= (WINDOW_HEIGHT + height) / 2) {
            mlx_pixel_put(mlx_data.mlx, mlx_data.win, x, y, 0x000000); // Draw black color for empty space
        } else {
            mlx_pixel_put(mlx_data.mlx, mlx_data.win, x, y, 0xFFFFFF); // Draw white color for walls
        }
    }
}

// Function to cast rays and render the walls
void cast_rays() {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
        // Calculate the position of the ray in the world
        float camera_x = 2 * x / (float)WINDOW_WIDTH - 1;
        Point ray_direction = {1, 0};
        Point player_position = {3, 5};

        // Calculate the ray's starting point and direction
        Ray ray = {player_position, ray_direction};
        int map_x = (int)player_position.x;
        int map_y = (int)player_position.y;

        // Calculate the length of the ray from one x or y-side to the next x or y-side
        Point side_dist = {0, 0};
        Point delta_dist = {fabs(1 / ray.direction.x), fabs(1 / ray.direction.y)};

        // Calculate the step and initial side distance
        int step_x, step_y;
        if (ray.direction.x < 0) {
            step_x = -1;
            side_dist.x = (player_position.x - map_x) * delta_dist.x;
        } else {
            step_x = 1;
            side_dist.x = (map_x + 1.0 - player_position.x) * delta_dist.x;
        }
        if (ray.direction.y < 0) {
            step_y = -1;
            side_dist.y = (player_position.y - map_y) * delta_dist.y;
        } else {
            step_y = 1;
            side_dist.y = (map_y + 1.0 - player_position.y) * delta_dist.y;
        }

        // Perform DDA (Digital Differential Analyzer) algorithm to find the first wall hit
        int hit = 0;
        while (!hit) {
            if (side_dist.x < side_dist.y) {
                side_dist.x += delta_dist.x;
                map_x += step_x;
                ray.direction.x = step_x;
                ray.direction.y = 0;
            } else {
                side_dist.y += delta_dist.y;
                map_y += step_y;
                ray.direction.x = 0;
                ray.direction.y = step_y;
            }

            // Check if the ray hits a wall
            if (map[map_x][map_y] == 1) {
                hit = 1;
            }
        }

        // Calculate the distance from the player to the wall
        float perp_wall_dist;
        if (ray.direction.x != 0) {
            perp_wall_dist = (map_x - player_position.x + (1 - step_x) / 2) / ray.direction.x;
        } else {
            perp_wall_dist = (map_y - player_position.y + (1 - step_y) / 2) / ray.direction.y;
        }

        // Calculate the height of the wall on the screen
        int wall_height = (int)(WINDOW_HEIGHT / perp_wall_dist);

        // Render the vertical line representing the wall on the screen
        draw_vertical_line(x, wall_height);
    }
}

int main() {
    mlx_data.mlx = mlx_init();
    mlx_data.win = mlx_new_window(mlx_data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Ray Casting");

    cast_rays();

    mlx_loop(mlx_data.mlx);
    return 0;
}

