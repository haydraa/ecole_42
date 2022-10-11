# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jghribi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 18:56:58 by jghribi           #+#    #+#              #
#    Updated: 2022/10/08 19:14:25 by jghribi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRC = ft_printf.c ft_putnbr.c\

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC.c=.o}

AR = ar rc

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} 
	${MAKE} -C .libft
	@cp libft/libft.a ${NAME}
	@mv libft.a ${NAME}
	${AR} ${NAME} ${OBJ}

#subsystem: 
#	${MAKE} -C /home/jalel/ecole_42/printf/libft

all: ${NAME} subsystem 

clean: 
	/bin/rm -f ${OBJ} 
	@make clean -C ${LIBFT}
fclean: clean 
	/bin/rm -f ${NAME}
	rm -f ${LIBFT}/libft.a
re: fclean all

.PHONY: all clean fclean re
