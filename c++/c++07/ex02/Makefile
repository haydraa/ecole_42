NAME = Arrays

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

CC = c++

CFLAGS = -g -Werror -Wextra -Wall -std=c++98 

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


