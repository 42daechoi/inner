# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 15:00:16 by kiyoon            #+#    #+#              #
#    Updated: 2022/08/24 16:52:49 by daechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        = ./main.c tokenization/token.c tokenization/withoutq_split.c tokenization/init.c tokenization/doubleq_split.c \
				parser/parser.c parser/parse_cmd.c parser/parse_cmd2.c parser/parse_cmd3.c parser/parse_cmd4.c parser/parse_heredoc.c parser/parse_heredoc2.c parser/parse_inre.c parser/parse_outre.c \
				fork/fd_handle.c fork/fork_and_pipe.c \
				utils/utils.c utils/utils2.c utils/utils3.c utils/utils4.c utils/utils5.c utils/utils6.c utils/utils7.c utils/utils8.c utils/utils9.c\
				builtin/change_dir.c builtin/export.c builtin/pwd.c builtin/echo.c builtin/env.c builtin/exit.c builtin/unset.c\
				free/free.c free/double.c \
				signal/sig_shell.c signal/interrupt.c

OBJS        = $(SRCS:.c=.o)

RM          = rm -f

LIBC        = ar rc

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror

COMFILE_FLAGS = -lreadline -L/goinfre/daechoi/.brew/opt/readline/lib

OBJ_FLAGS 	= -I/goinfre/daechoi/.brew/opt/readline/include

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	mv $(LIBFT)/$(LIBFT_LIB) .
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(OBJ_FLAGS) -c $< -o $@
	
all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS) 
	$(RM) $(OBJS_BONUS)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all bonus clean clean re
