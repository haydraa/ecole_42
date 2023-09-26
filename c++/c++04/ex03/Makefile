NAME = Materia 

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp \
		MateriaSource.cpp

OBJ = ${SRC:.cpp=.o}

CC = c++

CFLAGS = -g -Werror -Wextra -Wall -std=c++98 

OFLAGS = -Werror -Wextra -Wall -std=c++98

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


