# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 14:58:28 by daechoi           #+#    #+#              #
#    Updated: 2021/11/24 20:24:05 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
		   	ft_lstiter.c ft_lstclear.c
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
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJECTS)
	$(AR) $@ $(OBJECTS)

bonus:
	@make WITH_B=1 all

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re:	fclean all
