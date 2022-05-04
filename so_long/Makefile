# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 16:16:30 by daechoi           #+#    #+#              #
#    Updated: 2022/05/04 19:02:11 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -fsanitize=address -g3 -L./mlx -lmlx -framework OpenGL -framework AppKit *.c utils/get_next_line/*.c utils/*.c
	./a.out map.ber