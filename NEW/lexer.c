/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:12:57 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/13 15:55:27 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_parser.h"

t_token	*l_collect_wd(t_lexer *lexer)
{
	char	*val;
	char	*s;

	val = malloc(sizeof(char));
	val[0] = '\0';
	while (!is_operator(lexer->c) && !ft_isspace(lexer->c) && lexer->c != '\0')
	{
		if (lexer->c == '\'' || lexer->c == '\"')
		{
			s = continue_quotes(lexer, lexer->c);
			val = ft_strjoin(val, s);
			break ;
		}
		else
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

t_token	*l_adv_token(t_lexer *lexer, t_token *token)
{
	l_advance(lexer);
	return (token);
}

char	*l_char_str(t_lexer *lexer)
{
	char	*s;

	s = malloc(sizeof(char) * 2);
	s[0] = lexer->c;
	s[1] = '\0';
	return (s);
}
