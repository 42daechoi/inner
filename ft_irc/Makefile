# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 16:29:03 by daechoi           #+#    #+#              #
#    Updated: 2023/05/19 20:56:19 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
CC = c++
CFLAGS = --std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3
SRCS = main.cpp init.cpp error.cpp Socket/Socket.cpp Client/Client.cpp Channel/Channel.cpp Command/Command.cpp \
		Command/invite.cpp Command/join.cpp Command/kick.cpp Command/mode.cpp Command/nick.cpp Command/part.cpp \
		Command/pass.cpp Command/ping.cpp Command/privmsg.cpp Command/user.cpp Command/utils.cpp Command/who.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean all