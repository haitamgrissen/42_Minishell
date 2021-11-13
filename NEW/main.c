# include "new_parser.h"



int		is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int		skip_spaces(char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}


int		skip_quotes(char *line)
{
	int		i;
	char	c;

	i = 1;
	c = line[0];
	while (line[i] && line[i] != c)
		i++;
	return (i);
}

int		skip_other(char *line)
{
	int		i;

	i = 0;
	while (line[i] && !is_operator(line[i]) && !ft_isspace(line[i]))
		i++;
	return (i);
}


// t_part	**parse(char *line)
// {
// 	//t_part	**tab;
// 	int		i;
// 	int		last;
// 	char	*token;
// 	int		tmp_last;

// 	i = 0;
// 	while(line[i] != '\0')
// 	{
// 		i += skip_spaces(line + i);
// 		last = i;
// 		if (line[i] == '\'' || line[i] == '\"')
// 		{
// 			i += skip_quotes(line + i);
// 			if (!line[i])
// 			{
// 				printf("quote open\n");
// 				break ;//changed with error
// 			}
// 			token = ft_substr(line, last + 1, i - last - 1);
// 		}
// 		else
// 		{
// 			i += skip_other(line + i);
// 			token = ft_substr(line, last, i - last);
// 		}
// 		if(token[0])
// 		{
// 			ft_putstr_fd("|", 1);
// 			ft_putstr_fd(token, 1);
// 			ft_putstr_fd("|\n", 1);
// 		}
// 		free(token);
// 		token = NULL;
// 		i++;
// 	}
// 	return NULL;
// }


int main(int ac, char **av, char **env)
{
	t_parser	parser;
	t_lexer		*lexer;
	t_token		*token;
	t_token		**tokens;
	
	//t_part		**tab;
    

   	parser.line = (char*)malloc(sizeof(char));
	
	//parser.tab = (char**)malloc(sizeof(char *));
	//tab = malloc(2 * sizeof(t_part *));
    while(TRUE)
    {
        parser.line = readline("BASH$>: ");
		if (!parser.line)
		{
			ft_putstr_fd("exit", 1);
			return (0);
		}
        if (parser.line[0] =='\0')
			continue ;

        add_history(parser.line);


		lexer = init_lexer(parser.line);
		// while ((token = l_next_token(lexer)) != NULL)
		// {
		// 	printf("|type : %d\n|val : %s\n", token->type, token->value);
		// 	free(token->value);
		// 	free(token);
		// }
		tokens = parse(lexer);
		free(lexer);


		//system("leaks hada");
		free(parser.line);
		parser.line = NULL;
    }
    return(0);
}
