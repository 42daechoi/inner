# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 16:16:30 by daechoi           #+#    #+#              #
#    Updated: 2022/05/09 16:38:09 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#all:
#	gcc -L./mlx -lmlx -framework OpenGL -framework AppKit *.c utils/get_next_line/*.c utils/*.c
#	./a.out map.ber

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c image.c map.c move.c utils/ft_printerr.c utils/ft_putnbr_fd.c \
		utils/get_next_line/get_next_line.c utils/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
RM = /bin/rm -f

all: $(NAME)

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJECTS)
	arch -x86_64 $(CC) -o $(NAME) $(OBJECTS) -L./mlx -lmlx -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all