NAME = libft.a

SRC = *.c

CC = gcc

OBJ  = .c.o

CFLAGS = -Wall -Werror -Wextra

AR  = ar rc
all: $(NAME)

$(NAME) :
	$(cc) $(CFLAGS) -o $(NAME) $(SRC)
	$(AR) $(NAME) $(OBJ)
clean:
	/bin/rm -f *.o
fclean:
	/bin/rm -f $(NAME)

re : fclean all 
