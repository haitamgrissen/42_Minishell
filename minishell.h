#ifndef MINISHELL_H
#define MINISHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 10000
#define SYMBOL_1 //;
#define SYMBOL_2 // &
#define SYMBOL_3 // <
#define SYMBOL_4 // >
#define SYMBOL_5 // |
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
typedef struct shell
{
    char *str;
    char *first; // first command that has been entered " ls -al"  "first = ls" in this case
    char *second; // second arg
    int val;
}t_shell;
int hh;
int         get_next_line(int fd, char **line);
char        *ft_substr(char *s, unsigned int start, size_t len);
int         outtil(int fd, char **rest, char **line);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
char		*kayn_ster(char *str);
int			ft_strlen(char *s);
char		**ft_split(char *s, char c);
void        parse(char *str);
#endif 