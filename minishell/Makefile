NAME = minishell

CC = @clang
RM = @rm -rf
CFLAGS =  -g
LDFLAGS = -lreadline

SRC = ./sources/main.c \
	./sources/builtins/cd.c ./sources/builtins/echo.c ./sources/builtins/error.c ./sources/builtins/exit.c \
	./sources/builtins/export.c ./sources/builtins/signals.c ./sources/builtins/unset.c ./sources/builtins/unset2.c \
	./sources/env/env_lst.c ./sources/env/env_utils.c ./sources/env/env_utils2.c ./sources/env/env_replace_list.c \
	./sources/env/env_replace_str.c ./sources/exec/exec_cmd.c ./sources/exec/exec_path.c ./sources/exec/exec_one.c \
	./sources/exec/exec_two.c ./sources/parsing/pars_redir.c ./sources/parsing/parsing.c ./sources/parsing/parsing2.c \
	./sources/parsing/rm_quote.c ./sources/utils/cmd_utils.c ./sources/utils/cmd_utils2.c ./sources/utils/ft_utils.c \
	./sources/utils/ft_utils2.c ./sources/utils/ft_utils3.c ./sources/utils/ft_utils4.c ./sources/utils/ft_strtrim.c \
	./sources/utils/ft_utils5.c ./sources/exec/exec_utils.c ./sources/parsing/here_doc.c ./sources/parsing/utils_parsing.c \
	./sources/utils/ft_split.c ./sources/builtins/utils.c ./sources/exec/ft_utils2.c ./sources/exec/ft_utils3.c \
	./sources/builtins/utils_exit.c ./sources/builtins/utils_exit2.c ./sources/parsing/here_doc_utils.c \
	./sources/builtins/error_utils.c ./sources/builtins/utils_builtins.c ./sources/builtins/cd_utils.c

PURPLE	= \033[38;5;213m

MINININI	= @printf "$(PURPLE)        _       _     _                      \n"
MINININI1	= printf "$(PURPLE)  /\/\ (_)_ __ (_)___| |__   ___ _ __ _   _  \n"
MINININI2	= printf "$(PURPLE) /    \| | '_ \| / __| '_ \ / _ \ '__| | | | \n"
MINININI3	= printf "$(PURPLE)/ /\/\ \ | | | | \__ \ | | |  __/ |  | |_| | \n"
MINININI4	= printf "$(PURPLE)\/    \/_|_| |_|_|___/_| |_|\___|_|   \__,_| \n"
MINININI5	= printf "$(PURPLE)                                             \n"

MININI = $(MINININI);$(MINININI1);$(MINININI2);$(MINININI3);$(MINININI4);$(MINININI5);

OBJ = $(patsubst ./sources/%.c, .object/%.o, $(SRC))
INC = include/minishell.h

DIR_OBJ = .object
DIR_INC = include

$(NAME): $(OBJ) | $(DIR_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	$(MININI)

$(DIR_OBJ)/%.o: ./sources/%.c $(INC) Makefile | $(DIR_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

all: $(NAME)

re: fclean all

clean:
	$(RM) $(DIR_OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all re clean fclean
