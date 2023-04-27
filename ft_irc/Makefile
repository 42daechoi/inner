# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 16:29:03 by daechoi           #+#    #+#              #
#    Updated: 2023/04/27 19:17:49 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
CC = c++
CFLAGS = --std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3
SRCS = main.cpp init.cpp error.cpp Socket.cpp Command.cpp Client.cpp
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