/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:56:42 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/09 18:21:54 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void ft_putstr(char *str)
{
    int i = 0;
    if (!str)
        return;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1)     ;   
        i++;
    }

}


int main ()
{
    char *str ;
    char *command;
    int i = 0;
    int j = 0;
    str = (char *)malloc(sizeof(char)*100);
    str = " ec\"\"\"\"h\"\"o\"\" ";
    command = (char *)malloc(sizeof(char)*100);
    while (i < 22)
    {
        if (str[i] == '\"' )
            i++;
        else 
        {
            command[j] = str[i];
            j++;
        }
        i++;
    }
    //ft_putstr(command);
   printf("%s\n",command);
    return (0);
}