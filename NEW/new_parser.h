# ifndef NEW_PARSER_H
# define NEW_PARSER_H

#include "../EXECUTION/incs/builtins.h"

typedef struct s_parser
{
	char	*line;
	char	**tab;

}		t_parser;

typedef enum e_types
{
	WORD,
	IN,
	OUT,
	APND,
	HERDOC,
	PIPE,
}	t_types;

typedef struct s_lexer
{
	char			c;
	char			*content;
	unsigned int	i;
}					t_lexer;

typedef struct s_token
{
	char		*value;
	t_types		type;
	
}				t_token;


int		ft_isspace(int c);

t_token	*init_token(int type, char *value);


t_lexer	*init_lexer(char* contents);
void 	l_advance(t_lexer* lexer);
void 	l_skip_white(t_lexer* lexer);
t_token	*l_next_token(t_lexer* lexer);
t_token	*l_collect_string(t_lexer* lexer, char c);
t_token	*l_collect_wd(t_lexer* lexer);
t_token	*l_advance_token(t_lexer* lexer, t_token	* token);
char	*l_char_str(t_lexer* lexer);
t_token	*switch_token(t_lexer *lexer);


void	*ft_realloc(void *ptr, size_t newsize);

int		is_operator(char c);
t_token	**parse(t_lexer *lexer);

t_token	*expand_token(t_lexer *lexer);

t_token **ft_reallocc(t_token** current, t_token *to_add);

# endif

		/*
		// if (line[i] == '\'' || line[i] == '\"')
		// {
		// 	i += skip_quotes(line + i);
		// 	if (!line[i])
		// 	{
		// 		printf("quote open\n");
		// 		break ;//changed with error
		// 	}
		// 	token = ft_substr(line, last + 1, i - last - 1);
		// 	while(!is_operator(line[i]) && line[i] != ' ' && line[i])
		// 	{
		// 		tmp_last = i;
		// 		if (line[i] == '\'' || line[i] == '\"')
		// 		{
		// 			i += skip_quotes(line + i);
		// 			token = ft_strjoin(token, ft_substr(line, tmp_last, i - tmp_last + 1));
		// 		}
		// 		// else
		// 		// {
		// 		// 	printf("hahaha\n");
		// 		// 	i += skip_other(line);
		// 		// 	char *j = ft_substr(line, tmp_last - 1, i - tmp_last - 1);
		// 		// 	//printf("===%s===\n", j);
		// 		// 	token = ft_strjoin(token, j);
		// 		// }
		// 		i++;
		// 		tmp_last = i;
		// 	}
		// }
		// else
		// {
		// 	i += skip_other(line);
		// 	token = ft_substr(line, last , i - last);
		// }
		*/


// 	t_part	**parse(char *line)
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
// 			while(!is_operator(line[i]) && !ft_isspace(line[i]) && line[i] != '\0')
// 			{
// 				tmp_last = i;
// 				if (line[i] == '\'' || line[i] == '\"')
// 				{
// 					i += skip_quotes(line + i);
// 					token = ft_strjoin(token, ft_substr(line, tmp_last, i - tmp_last - 1));
// 				}
// 				else
// 				{
// 					i += skip_other(line + i);
// 					char *j = ft_substr(line, tmp_last - 1, i - tmp_last - 1);
// 					token = ft_strjoin(token, j);
// 				}
// 				i++;
// 			}
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