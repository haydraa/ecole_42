NAME = fdf

LIBFT = libft/libft.a

LIBIX = minilibx-linux/libmlx_Linux.a

MLX = -lXext -lX11

CC = clang

FLAGS = -Wall -Werror -Wextra

SRC = main.c get_next_line.c get_next_line_utils.c get_map.c to_img.c\

all: ${NAME}

${NAME}:
	@make -C libft
	@make -C minilibx-linux
	${CC} ${MLX} ${SRC} ${LIBIX} ${LIBFT} -o ${NAME}

clean:
	/bin/rm -f
	@make clean -C libft
	
fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
