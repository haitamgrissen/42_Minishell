# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 10:19:31 by sel-fcht          #+#    #+#              #
#    Updated: 2021/11/16 21:28:08 by hgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS= -Wall -Werror -Wextra -lreadline
FSANI = -fsanitize=address -g3

#souhail readline LIB AND INC

LDFLAGS =  -L/Users/sel-fcht/.brew/opt/readline/lib 
CPPFLAGS = -I/Users/sel-fcht/.brew/opt/readline/include

#HAITAM readline LIB AND INC

HGLIB = -L/Users/hgrissen/goinfre/hgrissen/.brew/opt/readline/lib 
HGINC =  -I/Users/hgrissen/goinfre/hgrissen/.brew/opt/readline/include

PARSING 	= 	parsing/lexer.c  parsing/lexer3.c parsing/parse_cmd.c parsing/parser.c  parsing/signals.c \
				parsing/lexer2.c parsing/lexer4.c parsing/parse_rdr.c parsing/refresh.c parsing/tokens.c
				
EXECUTION 	= execution/commands.c execution/paths.c execution/pipe.c execution/redirections.c

BUILTINS 	= 	builtins/builtins_utils.c builtins/env_utils.c builtins/export.c \
				builtins/cd.c builtins/env_var.c builtins/pwd.c \
				builtins/echo.c builtins/exit.c builtins/unset.c

UTILS		= utils/utils.c utils/utils2.c utils/utils3.c utils/utils4.c utils/utils5.c

SRC = $(EXECUTION) $(PARSING) $(BUILTINS) $(UTILS) minishell.c


NAME = MINI


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(HGLIB) $(HGINC)  $(SRC) -o $(NAME)


clean:
	rm -f $(NAME)

fclean: clean

re: fclean all