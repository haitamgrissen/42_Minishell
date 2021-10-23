/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:01:20 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/23 12:36:32 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int check_quotes(char *str)
{
    int i;
    int flag;
    flag = 0;
    i = 0;
    while(str[i]!= '\0')
    {
       if (str[i]== '\"' || str[i] == '\'') 
        {
            flag++;
            i++;
        }
        else
            i++;
    }
    if (flag % 2 == 1)
        return (0);
    else
        return (1);
    
}

void start_shit(char *str)
{
    int i;
    i = check_quotes(str);
    if (i == 0)
        ft_putstr("Minishell : Syntax Error With open Quotes\n");
    
    
    
    
}