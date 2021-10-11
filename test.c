/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:56:42 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/11 13:28:16 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
 #include <readline/readline.h>
#include <readline/history.h>



int main ()
{
    // char *str ;
    // char *command;
    // int i = 0;
    // int j = 0;
    // str = (char *)malloc(sizeof(char)*100);
    // str = " ec\"\"\"\"h\"\"o\"\" ";
    // command = (char *)malloc(sizeof(char)*100);
    // while (i < 22)
    // {
    //     if (str[i] == '\"' )
    //         i++;
    //     else 
    //     {
    //         command[j] = str[i];
    //         j++;
    //     }
    //     i++;
    // }
    // //ft_putstr(command);
    char *str = readline("test >");
    if (str == NULL)
    {
        write(0,"exit",4);
        exit (0);
    }
    //printf("%s\n",str);
    return (0);
}