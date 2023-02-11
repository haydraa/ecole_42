NAME = fdf

LIBFT = libft/libft.a

LIBIX = minilibx-linux/libmlx_Linux.a

MLX = -lXext -lX11

CC = clang


FLAGS = -Wall -Werror -Wextra 

SRC_B =  fdf_bonus/main_bonus.c fdf_bonus/get_next_line.c fdf_bonus/get_next_line_utils.c\
		fdf_bonus/get_map_bonus.c fdf_bonus/to_img_bonus.c\
		fdf_bonus/iso_projection_bonus.c fdf_bonus/mlx_hook_bonus.c fdf_bonus/repaire_bonus.c\

SRC = main.c get_next_line.c get_next_line_utils.c get_map.c to_img.c\
		iso_projection.c mlx_hook.c repaire.c\

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
