NAME = pipex

LIBFT = libft/libft.a

CC = clang

FLAGS = -g -Wall -Werror -Wextra

SRC = pipex_m/main.c pipex_m/pipex.c pipex_m/error.c pipex_m/somthing.c

SRC_BONUS = pipex_b/main_bonus.c pipex_b/pipex_bonus.c pipex_b/error_bonus.c\
			pipex_b/get_next_line.c pipex_b/get_next_line_utils.c\
			pipex_b/somthing.c pipex_b/utils.c pipex_b/utils2.c\

OBJ = ${SRC:.c=.o}

OBJB = ${SRC_BONUS:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@make -C libft
	${CC} -g ${OBJ} ${LIBFT} -o ${NAME}

bonus: ${OBJB} 
	@make -C libft
	${CC} -g ${OBJB} ${LIBFT} -o pipex_bonus

all: ${NAME}

clean:
	/bin/rm -f ${OBJ} ${OBJB}
	@make clean -C libft

fclean: clean
	/bin/rm -f ${NAME} pipex_bonus
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re

