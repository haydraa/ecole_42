NAME	= minishell

LIBFT	= libft/libft.a

CLANG	= clang

FLAGS	= -Wall -Wextra -Werror 

SRCS = parssing/main.c\
		builtins/echo.c  builtins/pwd.c  builtins/cd_utils.c\
    	builtins/cd.c builtins/exec.c  builtins/exec_utils.c\
    	builtins/env.c builtins/export.c builtins/export_utils.c\
	  	builtins/unset.c builtins/pipe.c builtins/signal.c\
		builtins/exit.c\

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CLANG) $(FLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CLANG) $(FLAGS) -lreadline  $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all


.PHONY:	clean fclean re
