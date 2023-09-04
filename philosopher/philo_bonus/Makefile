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

NAME = philo

SRC = main.c init_or.c routine.c init.c\

CC = clang 

CFLAGS = -Wall  -Werror -Wextra -pthread

OBJS = ${SRC:.c=.o} 

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} -g -O3 ${CFLAGS} ${SRC} -o ${NAME}
	
all: ${NAME}

clean:
	/bin/rm -f ${OBJS}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
