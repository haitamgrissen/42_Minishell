# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:58:33 by sel-fcht          #+#    #+#              #
#    Updated: 2021/10/24 15:23:51 by sel-fcht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = minishell.c\
	  minishell.h\
	  split.c\
	  get_next_line.c\
	  gnl_outils.c\
	  parsing.c
NAME = minishell

LDFLAGS=-L/Users/sel-fcht/.brew/opt/readline/lib
CPPFLAGS=-I/Users/sel-fcht/.brew/opt/readline/include

all: $(NAME)

$(NAME):

	gcc -lreadline $(LDFLAGS) $(CPPFLAGS) $(SRC) -g

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re : fclean all

test:
	gcc -lreadline $(LDFLAGS) $(CPPFLAGS) test.c minishell.h gnl_outils.c get_next_line.c
norme:
	norminette *.c *.h
push:
	git add .
	git commit -m "add tokens"
	git push