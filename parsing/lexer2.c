/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:12:34 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 10:34:51 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	if (lexer->c != '\0' && (int)lexer->i < ft_strlen(lexer->content))
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
