/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:12:08 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/26 20:15:29 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int string_dbl_quoted(char *str)
{
    int i;
    int dbl;
    i = 0;
    dbl = 0;
    while(str[i])
    {
        while(str[i] == '\"')
        {
            dbl++;
            i++;
        }
    }
    return (dbl);
}
int string_is_quoted(char *str)
{
    int i;
    i = 0;
    int sgl;
    sgl = 0;
    while(str[i]!='\0')    
    {
        while(str[i] == '\'')
        {
           sgl++;
           i++; 
        }
    } 
    return (sgl)
}

int is_quoted(char c)
{
    if (c == '\'' || c == '\"')
        return (1);
    else
        return (0);
}