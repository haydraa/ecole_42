NAME = ./push_swap

LIBFT = ./libft

SRC = push_swap.c error_case.c main.c op_swap.c push_swap2.c\
	  check_pos.c creat_stacks.c op_swap.c op_swap1.c op_swap2.c\
	  the_purge.c error_case2.c 

CC = clang 

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra 

AR = ar rc

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}


${NAME}: 
	@make -C ${LIBFT}
	@cp libft/libft.a ${NAME}
	@${AR} ${NAME} ${OBJ}
	
${NAME}: ${OBJ}

all: ${NAME} -o push_swap

clean:
	/bin/rm -f ${OBJ}
	@make clean -C ${LIBFT}

fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}/libft.a

re: fclean all

.PHONY: all clean fclean re
