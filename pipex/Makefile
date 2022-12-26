NAME = pipex

LIBFT = libft/libft.a

CC = clang

FLAGS = -Wall -Werror -Wextra

SRC = main.c 


all: ${NAME}

${NAME}:
	@make -C libft
	${CC} -g ${SRC} ${LIBFT} -o ${NAME}

clean:
	/bin/rm -f
	@make clean -C libft

fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re

