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

SRC = main.c get_args.c error.c creat_stack.c the_purge.c algo.c\
			op_swap.c op_swap1.c op_swap2.c algo_1.c algo_2.c

CC = clang 

CFLAGS = -Wall -Werror -Wextra 

${NAME}: 
	@make -C libft
	@${CC} -g ${FLAGS} ${SRC} ${LIBFT} -o ${NAME}
	
all: ${NAME}

clean:
	/bin/rm -f
	@make clean -C libft

fclean: clean
	/bin/rm -f ${NAME}
	/bin/rm -f ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
