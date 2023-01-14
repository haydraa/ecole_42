NAME = pipex

LIBFT = libft/libft.a

CC = clang

FLAGS = -Wall -Werror -Wextra

SRC = main.c pipex.c error.c

SRC_BONUS = main_bonus.c pipex_bonus.c error_bonus.c


${NAME}: bonus
	@make -C libft
	${CC} -g ${SRC} ${LIBFT} -o ${NAME}

bonus:
	@make -C libft
	${CC} -g ${SRC_BONUS} ${LIBFT} -o pipex_bonus

all: ${NAME} bonus

clean:
	/bin/rm -f
	@make clean -C libft

fclean: clean
	/bin/rm -f ${NAME} pipex_bonus
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re

