/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:15:26 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/09 13:10:30 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parse(char *str)
{
    t_shell *shell;
    
    shell->first = (char *)malloc(ft_strlen(str) + 1);
    int i;
    i = 0;
    while(str[i]!= '\0' && str[i] != ' ')
    {
        shell->first[i] = str[i];
        i++;
    }
    shell->first[i] = '\0';
    i = 0;
    while(shell->first[i] != '\0')
    {
        write(1,&shell->first[i],1);
        write(1,"\n",1);
        i++;
    }
}


char *ft_putstr(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        write(1,&str[i],1);
        i++;
    }
    return (str);
}
int main(int ac, char **av)
{
    t_shell *sh;
    sh = malloc(sizeof(t_shell));
    sh->str = ft_strdup("");
    printf("%s",sh->str);
    while(1)
    {
        write(1, "Minishell $>",12);
        get_next_line(0, &sh->str);
        parse(sh->str);
    }
    return(0);
}