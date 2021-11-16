#!/bin/bash -p

#gcc -L /goinfre/hgrissen/hgrissen/.brew/opt/readline/lib -I /goinfre/hgrissen/hgrissen/.brew/opt/readline/include -lreadline *.c  ../EXECUTION/builtins/*.c -o hada
export TERM=xterm
gcc -lreadline -L /Users/$USER/.brew/opt/readline/lib -I /Users/$USER/.brew/opt/readline/include *.c */*.c -o hada

#xterm-256color


   
#gcc -L /goinfre/hgrissen/hgrissen/.brew/opt/readline/lib -I /goinfre/hgrissen/hgrissen/.brew/opt/readline/include -lreadline *.c  ../EXECUTION/builtins/*.c -o hada


#gcc -L/Users/sel-fcht/.brew/opt/readline/lib -I -I/Users/sel-fcht/.brew/opt/readline/include -lreadline *.c */* 

#gcc -lreadline -L /Users/$USER/goinfre/$USER/.brew/opt/readline/lib -I /Users/$USER/goinfre/$USER/.brew/opt/readline/lib *.c */*.c  -o MINI