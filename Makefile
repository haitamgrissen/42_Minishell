LDFLAGS=-L/Users/sel-fcht/.brew/opt/readline/lib
CPPFLAGS=-I/Users/sel-fcht/.brew/opt/readline/include
run:
	gcc -lreadline $(LDFLAGS) $(CPPFLAGS) minishell.c minishell.h split.c get_next_line.c gnl_outils.c 
test:
	gcc -lreadline $(LDFLAGS) $(CPPFLAGS) test.c minishell.h gnl_outils.c get_next_line.c
norme:
	norminette *.c *.h
push:
	git add .
	git commit -m "Readline kinda"
	git push