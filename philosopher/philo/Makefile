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

SRC = main.c philo_utils.c

CC = clang 

CFLAGS = -Wall -Werror -Wextra 

${NAME}: 
	@${CC} -g ${CFLAGS} ${SRC} -o ${NAME}
	
all: ${NAME}

clean:
	/bin/rm -f

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
