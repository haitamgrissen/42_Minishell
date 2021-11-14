/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:12:00 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/14 22:37:12 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_parser.h"

t_token	*l_next_token(t_lexer *lexer)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		if (ft_isspace(lexer->c))
			l_skip_white(lexer);
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

char	*after_quotes(t_lexer *lexer, char *val)
{
	if (lexer->c == '\'' || lexer->c == '\"')
		return (ft_strjoin(val, continue_quotes(lexer, lexer->c)));
	else
		return (ft_strjoin(val, continue_word(lexer)));
}

t_token	*free_retnull(char	*val)
{
	free(val);
	return (NULL);
}

char	*get_exp_word(t_lexer *lexer)
{
	char	*val;
	char	*tmp;

	l_advance(lexer);
	if (lexer->c == '\"' || lexer->c == '$'
		|| lexer->c == ' ' || lexer->c == '\0')
		return (ft_strdup("$"));
	if (lexer->c == '?')
		return (expand_exit_error(lexer));
	val = ft_strdup("");
	while (!is_operator(lexer->c) && !ft_isspace(lexer->c)
		&& lexer->c != '\0' && lexer->c != '$' && lexer->c
		!= '\'' && lexer->c != '\"')
	{
		tmp = l_char_str(lexer);
		val = ft_strjoin(val, tmp);
		l_advance(lexer);
	}
	tmp = get_env_val(val);
	free(val);
	if (lexer->c == '$')
		tmp = ft_strjoin(tmp, get_exp_word(lexer));
	if (lexer->c == '\'' || lexer->c == '\"')
			tmp = ft_strjoin(tmp, continue_quotes(lexer, lexer->c));
	return (tmp);
}

t_token	*expand_token(t_lexer *lexer)
{
	t_token	*t;

	l_advance(lexer);
	t = l_collect_wd(lexer);
	free(t->value);
	t->value = get_env_val(t->value);
	return (t);
}
