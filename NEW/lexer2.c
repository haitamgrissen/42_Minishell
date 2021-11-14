/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:12:34 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/14 19:22:57 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_parser.h"

t_lexer	*init_lexer(char *line)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(struct s_lexer));
	lexer->content = line;
	lexer->i = 0;
	lexer->c = line[lexer->i];
	return (lexer);
}

void	l_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		lexer->i += 1;
		lexer->c = lexer->content[lexer->i];
	}
}

void	l_retreat(t_lexer *lexer)
{
	if (lexer->i > 0)
	{
		lexer->i -= 1;
		lexer->c = lexer->content[lexer->i];
	}
}

void	l_skip_white(t_lexer *lexer)
{
	while (ft_isspace(lexer->c))
		l_advance(lexer);
}

t_token	*switch_token(t_lexer *lexer)
{
	if (lexer->c == '|')
		return (l_adv_token(lexer, init_token(PIPE, l_char_str(lexer))));
	if (lexer->c == '<')
	{
		if (lexer->content[lexer->i + 1] == '<')
		{
			l_advance(lexer);
			return (l_adv_token(lexer, init_token(HERDOC, l_char_str(lexer))));
		}
		return (l_adv_token(lexer, init_token(IN, l_char_str(lexer))));
	}
	if (lexer->c == '>')
	{
		if (lexer->content[lexer->i + 1] == '>')
		{
			l_advance(lexer);
			return (l_adv_token(lexer, init_token(APND, l_char_str(lexer))));
		}
		return (l_adv_token(lexer, init_token(OUT, l_char_str(lexer))));
	}
	return (NULL);
}

t_token	*l_next_token(t_lexer *lexer)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		if (ft_isspace(lexer->c))
			l_skip_white(lexer);
		/*if (lexer->c == '$')
			return (expand_token(lexer));*/
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
