# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 18:52:07 by daechoi           #+#    #+#              #
#    Updated: 2022/07/18 18:55:05 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c sort.c calcul.c stack.c stack2.c arr_sort.c \
		cal_print.c cal_print2.c cal_print3.c
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
