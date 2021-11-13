/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:12:57 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/13 03:47:05 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "new_parser.h"

t_lexer	*init_lexer(char* line)
{
	t_lexer	*lexer;
	lexer = malloc(sizeof(struct s_lexer));
	lexer->content = line;
	lexer->i = 0;
	lexer->c = line[lexer->i];
	return (lexer);
}

void 	l_advance(t_lexer* lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		lexer->i += 1;
		lexer->c = lexer->content[lexer->i];
	}
}

void 	l_skip_white(t_lexer* lexer)
{
	while(ft_isspace(lexer->c))
	{
		l_advance(lexer);
	}
}

t_token	*switch_token(t_lexer *lexer)
{
	if (lexer->c == '|')
		return (l_advance_token(lexer, init_token(PIPE, l_char_str(lexer))));
	if (lexer->c == '<')
	{
		if (lexer->content[lexer->i + 1] == '<')
		{
			l_advance(lexer);
			return (l_advance_token(lexer, init_token(HERDOC, l_char_str(lexer))));
		}
		return (l_advance_token(lexer, init_token(IN, l_char_str(lexer))));
	}
	if (lexer->c == '>')
	{
		if (lexer->content[lexer->i + 1] == '>')
		{
			l_advance(lexer);
			return (l_advance_token(lexer, init_token(APND, l_char_str(lexer))));
		}
		return (l_advance_token(lexer, init_token(OUT, l_char_str(lexer))));
	}
	return NULL;
}

t_token	*l_next_token(t_lexer* lexer)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		if (ft_isspace(lexer->c))
			l_skip_white(lexer);
		if (lexer->c == '$')
			return (expand_token(lexer));
		if (!is_operator(lexer->c) && lexer->c != '\'' && lexer->c != '\"')
			return (l_collect_wd(lexer));
		if (lexer->c == '\"')
			return (l_collect_string(lexer, lexer->c));
		if (lexer->c == '\'')
			return (l_collect_string(lexer, lexer->c));
		return (switch_token(lexer));
	}
	return (NULL);
}

t_token	*expand_token(t_lexer *lexer)
{
	t_token *t;
	l_advance(lexer);

	t =  l_collect_wd(lexer);
	free(t->value);
	t->value = ft_strdup("EXPANSION!!!!!");
	return (t);
}

char	*expand_in_q(t_lexer *lexer)
{
	char	*val;
	char	*s;
	int		i;

	l_advance(lexer);
	i = 0;
	while (lexer->c != '\"' && lexer->c != ' '
			&& lexer->c != '$' && lexer->c != '?')
	{
		l_advance(lexer);
		i++;
	}
	if (lexer->c == '?')
		return (ft_strdup("100"));
	lexer->i--;
	if (i == 0)
		return (ft_strdup(""));
	val = ft_strjoin(val, ft_strdup("EXPANSION"));
	val = ft_strjoin(val, ft_strdup(""));
	return (val);
}

t_token	*l_collect_string(t_lexer* lexer, char c)
{
	char	*val;
	char	*s;

	val = malloc(sizeof(char));
	val[0] = '\0';
	// s = l_char_str(lexer);
	// val = ft_strjoin(val, s);
	l_advance(lexer);
	while (lexer->c != c)
	{
		if (lexer->c == '$' && c == '\"')	
			s = expand_in_q(lexer);
		else
			s = l_char_str(lexer);
		val = ft_strjoin(val, s);
		l_advance(lexer);
	}
	// s = l_char_str(lexer);
	// val = ft_strjoin(val, s);
	l_advance(lexer);
	return (init_token(WORD, val));
}
 
t_token	*l_collect_wd(t_lexer* lexer)
{
	char	*val;
	char	*s;

	val = malloc(sizeof(char));
	val[0] = '\0';

	while (!is_operator(lexer->c) && !ft_isspace(lexer->c) && lexer->c != '\0')
	{
		s = l_char_str(lexer);
		val = ft_strjoin(val, s);
		l_advance(lexer);
	}
	if (val[0] == '\0')
	{
		free(val);
		return (NULL);
	}
	return (init_token(WORD, val));
}

t_token	*l_advance_token(t_lexer* lexer, t_token	* token)
{
	l_advance(lexer);

    return (token);
}

char	*l_char_str(t_lexer* lexer)
{
	char* s;
	
	s = malloc(sizeof(char) * 2);
    s[0] = lexer->c;
    s[1] = '\0';

    return (s);
}

t_token	*init_token(int type, char *value)
{
	t_token	*token = malloc(sizeof(struct s_token));
    token->type = type;
    token->value = value;

    return (token);
}

void	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	cursize;

	if (ptr == 0)
		return (malloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = malloc(newsize);
	memcpy(ptr, newptr, cursize);
	free(ptr);
	return (newptr);
}