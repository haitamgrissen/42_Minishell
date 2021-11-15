/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:12:57 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 21:58:31 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*l_collect_wd(t_lexer *lexer)
{
	char	*val;
	char	*s;

	val = ft_strdup("");
	while (!is_operator(lexer->c) && !ft_isspace(lexer->c) && lexer->c != '\0')
	{
		if (lexer->c == '\'' || lexer->c == '\"')
		{
			s = continue_quotes(lexer, lexer->c);
			val = ft_strjoin(val, s);
			break ;
		}
		else if (lexer->c == '$')
		{
			s = get_exp_word(lexer);
			l_retreat(lexer);
		}
		else
			s = l_char_str(lexer);
		val = ft_strjoin(val, s);
		l_advance(lexer);
	}
	if (val[0] == '\0')
		return (free_retnull(val));
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

char	*expand_exit_error(t_lexer *lexer)
{
	l_advance(lexer);
	return (ft_itoa(g_exe.exite_err));
}

t_token	*open_quotes_err(char *val)
{
	free(val);
	g_exe.lexer_err = 1;
	return (NULL);
}
