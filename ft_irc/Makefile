# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 16:29:03 by daechoi           #+#    #+#              #
#    Updated: 2023/05/25 23:25:55 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
BOT = botclient
CC = c++
CFLAGS = --std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp utils.cpp error.cpp Socket/Socket.cpp Client/Client.cpp Channel/Channel.cpp Command/Command.cpp \
		Command/invite.cpp Command/join.cpp Command/kick.cpp Command/mode.cpp Command/nick.cpp Command/part.cpp \
		Command/pass.cpp Command/ping.cpp Command/privmsg.cpp Command/user.cpp Command/utils.cpp Command/who.cpp \
		Command/topic.cpp Command/superinvite.cpp
SRCS_BONUS = Bot/main.cpp Bot/Bot.cpp
OBJS = $(SRCS:.cpp=.o)
OBJS_BONUS = $(SRCS_BONUS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

bonus: $(BOT)

$(BOT): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BOT)

re: fclean all

.PHONY: all bonus clean fclean re