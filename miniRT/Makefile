# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 15:04:45 by kiyoon            #+#    #+#              #
#    Updated: 2022/12/12 17:31:33 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = miniRT

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        =./main.c \
				vector/vector3_1.c vector/vector3_2.c vector/vector3_3.c \
				trace/ray.c trace/light.c \
				parse/init_mlx.c parse/initalization.c parse/parse_A.c parse/parse_C.c parse/parse_L.c parse/parse_plane.c parse/parse_cylinder.c parse/parse_sphere.c \
				util/util1.c util/util2.c\
				figure/plane.c figure/sphere.c figure/cylinder.c figure/get_color.c \
				select/move.c select/select.c select/rotate.c select/resize.c select/init_select.c \
				terminal/manual.c

SRCS_BONUS	=./main_bonus.c \
				vector/vector3_1.c vector/vector3_2.c vector/vector3_3.c \
				trace/ray.c trace/light.c \
				parse/init_mlx.c parse/initalization.c parse/parse_A.c parse/parse_C.c parse/parse_L.c parse/parse_plane.c parse/parse_cylinder.c parse/parse_sphere.c \
				util/util1.c util/util2.c\
				figure/plane.c figure/sphere.c figure/cylinder.c figure/get_color.c \
				select/move.c select/select.c select/rotate.c select/resize.c select/init_select.c \
				terminal/manual.c \
				bonus/texture_bonus.c bonus/plane_bonus.c bonus/sphere_bonus.c bonus/parse_sphere_bonus.c bonus/init_mlx_bonus.c bonus/cone_bonus.c bonus/initalization_bonus.c bonus/parse_cone_bonus.c bonus/select_bonus.c bonus/light_bonus.c bonus/parse_L_bonus.c bonus/free_bonus.c

OBJS        = $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

RM          = rm -f

LIBC        = ar rc

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror #-g3 -fsanitize=address

MLX			= -L./mlx -lmlx -framework OpenGL -framework AppKit

ifdef WITH_BONUS
	OBJ = $(OBJS_BONUS)
else
	OBJ = $(OBJS)
endif

$(NAME) : $(OBJ)
	make all -C $(LIBFT)/
	make all -C mlx/
	mv $(LIBFT)/$(LIBFT_LIB) .
	$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ) $(LIBFT_LIB)

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

fclean : clean
	$(RM) $(NAME) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT)
	make clean -C mlx/

re : fclean all

.PHONY : all bonus clean clean re
