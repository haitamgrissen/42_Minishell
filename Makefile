# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 10:19:31 by sel-fcht          #+#    #+#              #
#    Updated: 2021/11/16 17:25:14 by hgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS= -Wall -Werror -Wextra -lreadline

LDFLAGS =  -L/Users/sel-fcht/.brew/opt/readline/lib 
CPPFLAGS = -I/Users/sel-fcht/.brew/opt/readline/include

HGLIB = -L/Users/hgrissen/goinfre/hgrissen/.brew/opt/readline/lib 
HGINC =  -I/Users/hgrissen/goinfre/hgrissen/.brew/opt/readline/include


SRC = *.c builtins/*.c parsing/*.c utils/*.c execution/*.c
#SRC =	builtins/builtins_utils.c\
		builtins/cd.c\
		builtins/echo.c\
		builtins/env_utils.c\
		builtins/env_var.c\
		builtins/exit.c\
		builtins/export.c\
		builtins/pwd.c\
		builtins/unset.c\
		execution/paths.c\
		execution/pipe.c\
		execution/redirections.c\
		parsing/lexer.c\
		parsing/lexer2.c\
		parsing/lexer3.c\
		parsing/lexer4.c\
		parsing/parse_cmd.c\
		parsing/parser.c\
		parsing/refresh.c\
		parsing/signals.c\
		parsing/tokens.c\
		execution.c\
		minishell.c\
		#incs/execution.h\
		#minishell.h incs/builtins.h\

NAME = MINI


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(HGLIB) $(HGINC)  $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all