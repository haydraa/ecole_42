# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jghribi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 14:09:14 by jghribi           #+#    #+#              #
#    Updated: 2023/02/11 19:29:09 by jghribi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
		ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
		ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_calloc.c\
		ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c\
		ft_base.c ft_pointeur.c ft_printf.c ft_putchar.c ft_putnbr.c\
		ft_putnbr1.c ft_putstr.c ft_strlen.c ft_lstadd_front.c\
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_atol.c\


CC = gcc

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
