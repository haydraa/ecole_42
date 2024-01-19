# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 14:25:07 by chmartin          #+#    #+#              #
#    Updated: 2024/01/03 09:07:48 by chmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ircserv

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -ggdb3 -std=c++98

SRC			:=	srcs/main.cpp \
				srcs/User.cpp \
				srcs/Server.cpp \
				srcs/Channel.cpp \
				srcs/ACommand.cpp \
				srcs/commands/Invite.cpp \
				srcs/commands/Pass.cpp \
				srcs/commands/UserName.cpp \
				srcs/commands/Kick.cpp \
				srcs/commands/Nick.cpp \
				srcs/commands/Mode.cpp \
				srcs/commands/Topic.cpp \
				srcs/commands/Join.cpp	\
				srcs/commands/Who.cpp	\
				srcs/commands/Message.cpp \
				srcs/commands/Part.cpp \
				srcs/commands/Quit.cpp

SRC_BOT		:= srcs/main_bot.cpp \
			   srcs/Bot.cpp

OBJ			:= $(SRC:.cpp=.o)

OBJ_BOT		:= $(SRC_BOT:.cpp=.o)

RM			:= rm -rf

ERASE		= \033[2K\r
BLUE		= \033[34m
YELLOW		= \033[33m
GREEN		= \033[32m
END			= \033[0m

%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@ $(FLAGS)
			
all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
			@printf "$(ERASE) $(GREEN)$@ ready\n$(END)"

bot:		$(OBJ_BOT)
			@$(CXX) $(CXXFLAGS) $(OBJ_BOT) -o bot

clean:		
			$(RM) $(OBJ)
			@printf "$(YELLOW) .o removed$(END)\n"

fclean:		
			$(RM) $(OBJ) $(OBJ_BOT) $(NAME) bot
			@printf "$(YELLOW) .o and $(NAME) removed$(END)\n"

re:			fclean all bot

.PHONY:		all clean fclean re bot
