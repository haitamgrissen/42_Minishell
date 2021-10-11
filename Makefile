# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:58:33 by sel-fcht          #+#    #+#              #
#    Updated: 2021/10/11 17:02:12 by sel-fcht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = minishell.c minishell.h split.c get_next_line.c gnl_outils.c
NAME = minishell

LDFLAGS=-L/Users/sel-fcht/.brew/opt/readline/lib
CPPFLAGS=-I/Users/sel-fcht/.brew/opt/readline/include
all: $(NAME)

$(NAME) :$(SRC)
	gcc -lreadline $(LDFLAGS) $(CPPFLAGS)  $(SRC)

clean:
	rm -rf *.o
fclean: clean
	rm -f $(NAME)
	rm -rf minishell
re : fclean all

test:
	gcc -lreadline $(LDFLAGS) $(CPPFLAGS) test.c minishell.h gnl_outils.c get_next_line.c
norme:
	norminette *.c *.h
push:
	git add .
	git commit -m "ls echo clear exit system commands"
	git push