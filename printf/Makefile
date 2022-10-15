# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jghribi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 18:56:58 by jghribi           #+#    #+#              #
#    Updated: 2022/10/12 13:10:44 by jghribi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putnbr.c ft_base.c ft_putnbr1.c ft_strlen.c\
		ft_putstr.c ft_putchar.c ft_pointeur.c\

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

AR = ar rc

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} 
	${AR} ${NAME} ${OBJ}

all: ${NAME} 

clean: 
	/bin/rm -f ${OBJ} 

fclean: clean 
	/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
