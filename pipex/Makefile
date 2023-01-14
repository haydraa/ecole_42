NAME = pipex

LIBFT = libft/libft.a

CC = clang

FLAGS = -Wall -Werror -Wextra

SRC = main.c pipex.c error.c

SRC_BOUNUS = main_bounus.c pipex_bonus.c error_bonus.c

all: ${NAME} 

${NAME}: bonus
	@make -C libft
	${CC} -g ${SRC} ${LIBFT} -o ${NAME}

${BONUS}:
	@make -C libft
	${CC} -g ${SRC_BONUS} ${LIBFT} -o pipex_bonus
clean:
	/bin/rm -f
	@make clean -C libft

fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re

