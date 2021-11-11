/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:15:26 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/11 04:22:12 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../EXECUTION/incs/execution.h"


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

int	ft_count_words(char const *s, char c)
{
	int		i;
	size_t	j;
	int		compt1;
	int		compt2;

	compt2 = 0;
	compt1 = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"' && compt2 == 0)
			compt1++;
		if (s[i] == '\'' && compt1 == 0)
			compt2++;
		if (((s[i] == c && s[i + 1] != c && s[i + 1]) || (i == 0 && s[i] != c))
			&& (compt1 % 2 == 0) && (compt2 % 2 == 0))
			j++;
		i++;
	}
	if (j == 0)
		j = 1;
	return (j);
}

int	ft_lw(char const *s, char c, int i)
{
	size_t	j;
	int		compt1;
	int		compt2;

	compt2 = 0;
	compt1 = 0;
	j = 0;
	while ((s[i] != c && s[i] != '\0') || (compt1 == 1 && s[i] != '\0')
		|| (compt2 == 1 && s[i] != '\0'))
	{
		if (s[i] == '"' && compt2 == 0)
			compt1++;
		if (s[i] == '\'' && compt1 == 0)
			compt2++;
		i++;
		j++;
		if (compt1 == 2)
			compt1 = 0;
		if (compt2 == 2)
			compt2 = 0;
	}
	return (j);
}

void	*ft_free(char **s, int i)
{
	i = 0;
	while (s[i] != 0)
		free(s[i++]);
	free(s);
	return (0);
}

char	**boucle_help(char **str, char const *s, char c, int i)
{
	int	j;
	int	compt1;
	int	compt2;
	int	k;

	k = 0;
	compt2 = 0;
	compt1 = 0;
	while (s[k] != '\0' && i < ft_count_words(s, c))
	{
		j = 0;
		while (s[k] == c)
			k++;
		str[i] = (char *)malloc(sizeof(char) * ((ft_lw(s, c, k) + 1)));
		while ((s[k] != c && s[k] != '\0') || (compt1 % 2 == 1 && s[k] != '\0')
			|| (compt2 % 2 == 1 && s[k] != '\0'))
		{
			compt1 += (s[k] == '"' && compt2 % 2 == 0);
			compt2 += (s[k] == '\'' && compt1 % 2 == 0);
			str[i][j++] = s[k++];
		}
		str[i++][j] = '\0';
	}
	str[i] = 0;
	return (str);
}

char	**split_pipe(char const *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	str = (char **)malloc(sizeof(char *) * ((ft_count_words(s, c) + 1)));
	str = boucle_help(str, s, c, i);
	return (str);
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

int tab_len(char **s) {

    int len;

    len = 0;
    if (s)
        while (s[len])
            len++;
    return len;
}

char    **realloc_tokens(char **s, char *t) {

    int i;
    int len;
    char    **n;

    i = 0;
    len =  tab_len(s);
    n =  (char **)malloc(sizeof(char *) * (len + 2));
    while (i < len)
    {
        n[i] = s[i];
        i++;
    }
    if (t)
    {
        n[i] = t;
        i++;
    }
    n[i] = NULL;
    return n;

}

char    *fill_tokens(char *line, int *pos, char c) {

    int i;
    char *t;
    int insgl;
    int indbl;
    
    i = 0;
    insgl = 0;
    indbl = 0;
    while (line[i] != '\0')
    {
        while (line[i] == '\"')
        {
            i++;
            indbl++;
        }    
        while (line[i] == '\'')
        {
            i++;
            insgl++;
        }
        if (line[i] == c && (indbl % 2 == 0) && (insgl % 2 == 0))
            break ;
        i++;
    }
    t = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (line[i] != '\0') 
    {
        while (line[i] == '\"')
        {
            i++;
            indbl++;
        }    
        while (line[i] == '\'')
        {
            i++;
            insgl++;
        }
        if (line[i] == c && (indbl % 2 == 0) && (insgl % 2 == 0))
            break ;
        else
        {
            t[i] = line[i];
            i++;
        }
    }
    *pos += i;
    return t;
}
char    *get_inquotes(char *line, int *pos, int *insgl, int *indbl, char c) {

    int i;
    char *t = NULL;
    int a = *insgl;
    int b = *indbl;
    
    
    i = 0;
    while (line[i] != '\0') {
        
        while (line[i] == '\"')
        {
            i++;
            (a)++;
        }    
        while (line[i] == '\'')
        {
            i++;
            (b)++;
        }
        if (line[i] == c  && ((a) % 2 == 0) && ((b) % 2 == 0))
            break ;
        i++;
    }
    t = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (i < strlen(line) && line[i] != '\0') {

        while (i < strlen(line) && line[i] == '\"')
        {
            i++;
            (*indbl)++;
        }    
        while (i < strlen(line) && line[i] == '\'')
        {
            i++;
            (*insgl)++;
        }
        if (i < strlen(line) && line[i] == c )
            break ;
        else {
            if (i < strlen(line)) {
                t[i] = line[i];
                i++;
            }
        }
    }
    t[i] = '\0';
    *pos += i + 1;
    return t;
}
char    **split_quotes( char *s , char c) {

    int i;
    int insgl;
    int indbl;
    int cnt = 0;

    i = 0;
    insgl = 0;
    indbl = 0;
    char    **tokens = NULL;
    cnt = check_quotes(s);
    while (i < strlen(s) && s[i] != '\0') 
    {
        while (i < strlen(s) &&  s[i] == '\"')
        {
            i++;
            indbl++;
        }    
        while (i < strlen(s) && s[i] == '\'')
        {
            i++;
            insgl++;
        }  
        printf("--->DOUBLE QUOTES = %d\n",indbl); 
        while (i < strlen(s) &&  s[i] == c)
            i++;
        if (i < strlen(s) &&  s[i] != c )
            tokens = realloc_tokens(tokens, fill_tokens(s + i, &i, c));
        else
            tokens = realloc_tokens(tokens, get_inquotes(s + i, &i, &insgl, &indbl, c)); //blan
        if (s[i] == c && (indbl % 2 == 0) && (insgl % 2 == 0))
           i++;
    }
    printf("--> HOW MUCH I EQUAL = %d",i);
    i = 0;
    if (tokens)
    {
        while (tokens[i] != NULL) {
        printf("|%s|", tokens[i]);
        i++;
    }
    }
    return tokens;
}
int quotes(char *str, char c, int i)
{
    while(str[i] != c && str[i] != '\0')
        i++;
    return (i + 1);
}
void split_command(t_cmd *shell)
{
    int i;
    int len;
    i = 0;
    while(shell->cmd[i] != '\0' && shell->cmd[i] == ' ' && shell->cmd[i] == '\t')
    {
        if (shell->cmd[i] == '\'' || shell->cmd[i] == '"')
            i = quotes(shell->cmd, shell->cmd[i], i);
        else
            i++;
    }
    len = ft_strlen(shell->cmd);
    //printf("---->%d %d", i, len);
}

int count_tabs(char **tab)
{
    int i;
    i = 0;
    if (tab)
    {
        while(tab[i] != NULL)
            i++;
    }
    return (i);
}
char **split_tabs(char **line)
{
    int i;
    int j;
    char **tmp;
    i = 0;
    tmp = (char **)malloc(sizeof(char *) * (count_tabs(line) +1));
    while (line[i])
    {
        j = 0;
        while(line[i][j] == ' ')
            j++;
        tmp[i] = ft_strdup(line[i] + j);
        i++;
    }
    tmp[i] = 0;
    return (tmp);
    
}
int count_words(char *s, char c)
{
    int i;
    int j;
    int sgl;
    int dbl;

    i = 0;
    j = 0;
    sgl = 0;
    dbl = 0;
    while(s[i] != '\0')
    {
        if (s[i] == '\"' && sgl == 0)
            dbl++;
        if (s[i] == '\'' && dbl == 0)
            sgl++;
        if (((s[i] == c && s[i + 1] != c &&s[i + 1]) || (i == 0 && s[i] != c) )
            && (dbl % 2 == 0) && (sgl % 2 == 0))
                j++;
            i++;
    }
    if (j==0)
        j =1;
    return (j);
}
int wod(char *s, char c , int i)
{
    int j;
    int sgl;
    int dbl;
    sgl = 0;
    dbl = 0;
    j = 0;
   while((s[i] != c && s[i] != '\0') || (dbl == 1 && s[i] != '\0')
    || (sgl == 1 && s[i] != '\0'))
    {
        if (s[i] == '\"' && sgl == 0)
            dbl++;
        if(s[i] == '\'' && dbl == 0)
            sgl++;
        i++;
        j++;
        if (sgl == 2)
            sgl = 0;
        if (dbl == 2)
            dbl = 0; 
    }
    return (j);
}
char **treat_it(char **str, char *s, char c, int i)
{
    int j;
    int sgl;
    int dbl;
    int k;

    k = 0;
    sgl = 0;
    dbl = 0;
    while(s[k] != '\0' && i < count_words(s, c))
    {
        j = 0;
        while(s[k] == c)
            k++;
        str[i] = (char *)malloc(sizeof(char) * ((wod(s,c,k) +1)));
        while ((s[k] != c && s[k] != '\0') || (sgl % 2 == 1 && s[k] != '\0')
        || (dbl % 2 == 1 && s[k] != '\0'))
        {
            dbl += (s[k] =='\"' && sgl % 2 == 0);
            sgl += (s[k] == '\'' && dbl % 2 == 0);
            str[i][j++] = s[k++];
        }
        str[i++][j] = '\0';
    }
    str[i] = 0;
    return (str);
}


// t_cmd *next_input(t_cmd *shell, char **line)
// {
//     int i;

//     i = 1;
//     shell = shell->next;
//     while(line[i])
//     {
//         shell = spaces(shell, line[0]);
//         if (line[i + 1])
//         {
//             shell->next = (t_cmd *)malloc(sizeof(t_cmd));
//             if (!shell->next)
//                 return (NULL);
//             shell = shell->next;
//         }
//         i++;
//     }
//     return (shell);
// }

char **split_pipes(char *s, char c)
{
    char **str;
    int i;
    
    i = 0;
    if (!s)
        return(0);
    str = (char **)malloc(sizeof(char *) * ((count_words(s,c) + 1)));
    str = treat_it(str, s, c, i);
    return (str);
    
}


int main(int ac, char **av, char **env)
{
    t_cmd *shell;
    
    hh = 0;
    char **line;
    shell = malloc(sizeof(t_shell));
    shell->cmd = (char*)malloc(sizeof(char) + 4);
    while(1)
    {
        shell->cmd = readline("Minishell $>: ");
        if (shell->cmd == NULL)
        {
            ft_putstr("exit");
            exit(0);
        }
        if (*shell->cmd == '\0')
        {
            ft_putstr("Enter a command\n");
            continue;
        }
        add_history(shell->cmd);
        split_command(shell);
        line = split_pipe(shell->cmd,'|');
        line = split_tabs(line);
        shell->tokens = line;
        //return 0;
        //printf("-->|%s|\n",line[3]);
      //  shell = parse_this(line);
       // printf("\n=====|%s|------>\n" ,shell->args[0]);
        //printf("\n=====|%s|------>\n" ,shell->args[1]);
        //printf("\n=====|%s|------>\n" ,shell->args[2]);  
        
        int j = 0;
        int x = 0;
    }
    return(0);
}