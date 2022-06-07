# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 17:16:21 by daechoi           #+#    #+#              #
#    Updated: 2022/06/07 16:58:25 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c pipex.c fileopen.c
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ -L./libft -lft

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $^
	
clean:
	$(RM) WITH_B=1 $(OBJ)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re:	fclean all
