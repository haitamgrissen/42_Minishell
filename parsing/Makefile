# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:58:33 by sel-fcht          #+#    #+#              #
#    Updated: 2021/11/11 05:07:06 by hgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = minishell.c\
	  minishell.h\
	  split.c\
	  get_next_line.c\
	  gnl_outils.c\
	  parsing.c\
	  
NAME = minishell

LDFLAGS=-L /goinfre/hgrissen/hgrissen/.brew/opt/readline/lib
CPPFLAGS=-I /goinfre/hgrissen/hgrissen/.brew/opt/readline/include

all	:	$(NAME)

$(NAME)	:	$(SRC)
	gcc  -lreadline $(LDFLAGS) $(CPPFLAGS)  $(SRC)

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