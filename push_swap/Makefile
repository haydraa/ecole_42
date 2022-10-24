NAME = push_swap

LIBFT = /home/jalel/ecole_42/push_swap/libft

SRC = push_swap.c\

CC = gcc

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@make -C ${LIBFT}
	@cp libft/libft.a ${NAME}
	@${AR} ${NAME} ${OBJ}

all: ${NAME}

clean:
	/bin/rm -f ${OBJ}
	@make clean -C ${LIBFT}

fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}/libft.a

re: fclean all

.PHONY: all clean fclean re
