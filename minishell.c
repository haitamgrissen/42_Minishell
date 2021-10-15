/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:15:26 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/14 19:08:18 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



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

char * parse_second_arg(char *str)
{
    int i;
    int j = 0;
    char *tmp;
    tmp = (char *)malloc(sizeof(str));
    i = 0;
    while(str[i]!= '\0')
    {
    if (str[i] == ' ')
            i++;
    if (str[i] == '-' )
        {
            while(str[i]    != '\0')
            {
                tmp[j] = str[i];
                i++;
            j   ++;
            }
        }
        else
            i++;
    }
   return(tmp);
}
char *take_second(char *str)
{
    int i;
    char *tmp;
    tmp = (char *)malloc(sizeof(str));
    int j = 0;
    i = 0;
    while(str[i] != '\0' && str[i] != ' ')
        i++;
    while(str[i]!= '\0')
    {
        tmp[j] = str[i];
        i++;
        j++;
    }
    return (tmp);
}
int  subtstr(char *str)
{
    int i; 
    i = 0;
    while(str[i]!= '\0')
    {
        i++;
    }
    printf("Lenght of the str is %d\n",i);
    return (i);
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
    tmp = (char *)malloc(sizeof(str));
    check_modulo(str);
    while(str[i] != '\0')
    {
        if (str[i] == '\"' || str[i] =='\'' )
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
void pwd_execute()
{
    system("pwd");
}
void clear_execute()
{
    system("clear");
}
void ls_execute()
{
    int i;
    i= system("ls");
    printf("value returned :%d \n",i);
}
void echo_execute()
{
   system("echo");
}
void execute(char *all, char *arg)
{
    int i;
    i = 0;
    if (ft_strcmp(arg,"echo") == 0)
        echo_execute();
    else if (ft_strcmp(arg,"ls")==0)
        ls_execute();
    else if (ft_strcmp(arg, "exit" ) == 0)
        exit(0);
    else if (ft_strcmp(arg, "clear")==0)
        clear_execute();
    else if (ft_strcmp(arg, "pwd") == 0)
        pwd_execute();
    else
            ft_putstr("Command not Found$\n");
        
}
void parse(char *str)
{
    t_shell *shell;
    shell = malloc(sizeof(t_shell));
    
    int i;
    i = 0; 
    shell->first = (char *)malloc(ft_strlen(str) + 1);
    while(str[i] != '\0' && str[i] != ' ')
    {
        shell->first[i] = str[i];
        i++;
    }
    shell->first[i] = '\0';
    //shell->val = subtstr(str);
    shell->second = take_second(str);
    shell->second = parse_second_arg(shell->second);
    printf("Second Argument is : %s\n",shell->second);
    shell->first = treat_quotes(shell->first);
    execute(shell->str, shell->first);
}

int main(int ac, char **av)
{
    t_shell *sh;
    hh = 0;
    sh = malloc(sizeof(t_shell));
    sh->str = (char*)malloc(sizeof(char) + 4);
    //sh->str = ft_strdup("");
    //printf("%s",sh->str);
    while(1)
    {
        sh->str = readline("Minishell $>: ");
        if (sh->str == NULL)
        {
            ft_putstr("exit");
            exit(0);
        }
        //ft_putstr(sh->str);
        parse(sh->str);
    }
 
    return(0);
}