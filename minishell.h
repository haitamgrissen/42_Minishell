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

char *delimi = ";&<>|";

int         get_next_line(int fd, char **line);
char        *ft_substr(char *s, unsigned int start, size_t len);
#endif 