NAME = N_zombie 

SRC = main.cpp ZombieHorde.cpp Zombie.cpp 

OBJ = ${SRC:.cpp=.o}

CC = c++

CFLAGS = -g -Wextra -Wall -std=c++98 

OFLAGS = -Werror -Wextra -Wall

all : ${NAME}
	
${NAME} : ${OBJ}
	${CC} ${OFLAGS} ${OBJ} -o ${NAME}

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}
fclean: clean
	@rm -f ${NAME}
re : fclean all 

.PHONY: all clean fclean re


