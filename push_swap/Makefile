# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jghribi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 11:56:28 by jghribi           #+#    #+#              #
#    Updated: 2022/11/28 16:37:04 by jghribi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

SRC = push_swap.c error_case.c main.c op_swap.c push_swap2.c\
	  check_pos.c creat_stacks.c op_swap1.c op_swap2.c\
	  the_purge.c error_case2.c push_swap_v2.c

CC = clang 

#OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra 

#AR = ar rc

#.c.o:
#	${CC} ${FLAGS} -c $< -o ${<:.c=.o}


${NAME}: 
	@make -C libft
	@${CC} ${FLAGS} ${SRC} ${LIBFT} -o ${NAME}
	
all: ${NAME}

clean:
	/bin/rm -f
	@make clean -C libft

fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
