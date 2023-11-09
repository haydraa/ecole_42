NAME = cub3D

LIBFT = libft/libft.a

LIBIX = minilibx-linux/libmlx_Linux.a

MLX = -lXext -lX11

CC = clang


FLAGS = -Wall -Werror -Wextra -g 

SRC_B = 
SRC = main.c get_next_line.c get_next_line_utils.c get_map.c\
	  get_map_utils.c start_mlx.c get_pos_player.c\
	  start_mlx_utils.c ft_error.c ft_textur_init.c ft_sprites.c\
	  ft_draw.c ft_color_init.c init_player.c ft_raycasting.c ft_dda.c move.c rotate.c\
	  init_utils.c lite_check.c mlx_hook.c

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
	${CC} -lm  ${MLX} ${FLAGS} ${OBJ_B} ${LIBIX} ${LIBFT} -o ${NAME}

all: ${NAME}

clean:
	/bin/rm -f $(OBJ) $(OBJ_B)
	@make clean -C libft
	
fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
