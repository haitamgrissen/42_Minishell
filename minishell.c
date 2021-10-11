/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:15:26 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/11 13:29:25 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <readline/readline.h>
#include <readline/history.h>
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

void check_modulo(char *str)
{
    int i;
    int flag;
    i = 0;
    flag = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '\"' || str[i] == '\'')
            {
                flag++;
                i++;
            }
        else
            i++;
    }
    if (flag % 2 == 1)
        exit(0);
}

char *treat_quotes(char *str)
{
    int i;
    int j;
    char *tmp;
    i = 0;
    j = 0;
    tmp = (char *)malloc(sizeof(char));
    check_modulo(str);
    while(str[i] != '\0')
    {
        if (str[i] == '\"' || str[i] =='\'')
            i++;
        else
        {
            tmp[j] = str[i];
            j++;    
        }
    i++;
    }
    return (tmp);
}
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void echo_execute()
{
    write(1, "ECHO SUCCESS",13);
}
void execute(char *all, char *arg)
{
    int i;
    i = 0;
    if (ft_strcmp(arg,"echo") == 0)
        echo_execute();
    else if (ft_strcmp(arg, "exit" ) == 0)
        exit(0);
    else
            ft_putstr("Command not Found$\n");
        
}
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
    shell->first = treat_quotes(shell->first);
    i = 0;
    while(shell->first[i] != '\0')
    {
        write(1,&shell->first[i],1);
        i++;
    }
    execute(shell->str, shell->first);
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
        readline(sh->str);
        parse(sh->str);
    }
    // while(readline(sh->str))
    // {
    //     ft_putstr("Minishell  $>");
    //     parse(sh->str);
    // }
    return(0);
}