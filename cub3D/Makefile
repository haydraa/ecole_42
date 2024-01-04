NAME = cub3D

LIBFT = libft/libft.a

LIBIX = minilibx-linux/libmlx_Linux.a

MLX = -lXext -lX11

CC = clang


FLAGS = -Wall -Werror -Wextra -g 

SRC_B = cub3D_bonus/main_bonus.c cub3D_bonus/get_next_line.c cub3D_bonus/get_next_line_utils.c cub3D_bonus/get_map_bonus.c\
	  cub3D_bonus/get_map_utils_bonus.c cub3D_bonus/start_mlx_bonus.c cub3D_bonus/get_pos_player_bonus.c\
	  cub3D_bonus/start_mlx_utils_bonus.c  cub3D_bonus/ft_textur_init_bonus.c \
	  cub3D_bonus/ft_draw_bonus.c cub3D_bonus/ft_color_init_bonus.c \
	  cub3D_bonus/ft_raycasting_bonus.c cub3D_bonus/ft_dda_bonus.c cub3D_bonus/move_bonus.c cub3D_bonus/rotate_bonus.c\
	  cub3D_bonus/init_utils_bonus.c cub3D_bonus/lite_check_bonus.c cub3D_bonus/mlx_hook_bonus.c cub3D_bonus/get_colors_bonus.c \
	  cub3D_bonus/utils_bonus.c cub3D_bonus/check_map_bonus.c
SRC = main.c get_next_line.c get_next_line_utils.c get_map.c\
	  get_map_utils.c start_mlx.c get_pos_player.c\
	  start_mlx_utils.c  ft_textur_init.c \
	  ft_draw.c ft_color_init.c \
	  ft_raycasting.c ft_dda.c move.c rotate.c\
	  init_utils.c lite_check.c mlx_hook.c get_colors.c \
	  utils.c check_map.c

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

${NAME}: $(OBJ)
	@make -C libft
	@make -C minilibx-linux
	${CC} -lm  ${MLX} ${FLAGS} ${OBJ} ${LIBIX} ${LIBFT} -o ${NAME}

bonus: $(OBJ_B)
	@make -C libft
	@make -C minilibx-linux
	${CC} -lm  ${MLX} ${FLAGS} ${OBJ_B} ${LIBIX} ${LIBFT} -o cub3D_bonus

all: ${NAME}

clean:
	/bin/rm -f $(OBJ) $(OBJ_B)
	@make clean -C libft
	
fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
