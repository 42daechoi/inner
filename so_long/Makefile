# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 16:16:30 by daechoi           #+#    #+#              #
#    Updated: 2023/01/12 19:02:25 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c image.c map.c move.c ft_printerr.c ft_putnbr_fd.c \
		get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
RM = /bin/rm -f

all: $(NAME)

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $^

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L./mlx -lmlx -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all