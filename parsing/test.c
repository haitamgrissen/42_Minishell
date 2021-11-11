/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:56:42 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/10 21:51:18 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
 #include <readline/readline.h>
#include <readline/history.h>
int *fds;


void redirect(char *str)
{
    int i;
    int *fds;
    char *
}
int main ()
{
    //char *str = ">> ok" ;
    char *buff;
    buff = malloc(sizeof(char ) * 4);
    int i = 0;
    while(1)
    {
        buff = readline("Minishell $>: ");
        //buff == >> file1 >> file2 >>
        redirect(buff);
     //   break;
    }
    return (0);
}