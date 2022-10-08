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

SRC = *.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC.c=.o}

AR = ar rc

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} 
	${AR} ${NAME} ${OBJ}

all: ${NAME}
