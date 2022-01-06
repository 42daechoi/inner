# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 17:54:17 by daechoi           #+#    #+#              #
#    Updated: 2022/01/06 18:25:45 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
SRC = ./utils/ft_isdigit.c ./utils/ft_itoa.c ./utils/ft_putchar_fd.c \
		./utils/ft_malloc_nbr_base.c ./utils/ft_putstr_fd.c ./utils/ft_strchr.c\
		./utils/ft_strdup.c ./utils/ft_strjoin.c ./utils/ft_strlen.c \
		ft_printf.c format.c format2.c
SRC_BONUS = ./utils/ft_isdigit.c ./utils/ft_itoa.c ./utils/ft_putchar_fd.c \
		./utils/ft_malloc_nbr_base.c ./utils/ft_putstr_fd.c ./utils/ft_strchr.c\
		./utils/ft_strdup.c ./utils/ft_strjoin.c ./utils/ft_strlen.c \
		ft_printf_bonus.c format_bonus.c format2_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
RM = /bin/rm -f

ifdef WITH_B
	OBJECTS = $(OBJ) $(OBJ_BONUS)
else
	OBJECTS = $(OBJ)
endif

all: $(NAME)

.c.o: $(SRC) $(SRC_BONUS)
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJECTS)
	$(AR) $@ $(OBJECTS)

bonus:
	make WITH_B=1 all

clean:
	$(RM) ${OBJ} ${OBJ_BONUS}

fclean: clean
	$(RM) $(NAME)

re:	fclean all