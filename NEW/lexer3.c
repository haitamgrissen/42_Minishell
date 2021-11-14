/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:46:44 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/14 22:44:27 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_parser.h"

char	*get_env_val(char *key)
{
	t_envs	*node;

	node = getenv_node(key);
	if (node != NULL)
		return (ft_strdup(node->val));
	else
		return (NULL);
}

char	*expand_in_q(t_lexer *lexer)
{
	char	*val;
	char	*tmp;

	l_advance(lexer);
	if (lexer->c == '\"' || lexer->c == '$' || lexer->c == ' ')
		return (ft_strdup("$"));
	if (lexer->c == '?')
		return (expand_exit_error(lexer));
	val = ft_strdup("");
	while (lexer->c != '\"' && lexer->c != ' '
		&& lexer->c != '$' && lexer->c != '\0')
	{
		tmp = l_char_str(lexer);
		val = ft_strjoin(val, tmp);
		l_advance(lexer);
	}
	tmp = get_env_val(val);
	free(val);
	if (lexer->c == ' ')
		tmp = ft_strjoin(tmp, ft_strdup(" "));
	if (lexer->c == '$')
		tmp = ft_strjoin(tmp, expand_in_q(lexer));
	return (tmp);
}

t_token	*l_collect_string(t_lexer *lexer, char c)
{
	char	*val;
	char	*s;

	val = ft_strdup("");
	l_advance(lexer);
	while (lexer->c != c && lexer->c != '\0')
	{
		if (lexer->c == '$' && c == '\"')
		{
			s = expand_in_q(lexer);
			l_retreat(lexer);
		}
		else
			s = l_char_str(lexer);
		val = ft_strjoin(val, s);
		l_advance(lexer);
	}
	if (lexer->c != c)
		return (open_quotes_err(val));
	l_advance(lexer);
	if (!is_operator(lexer->c) && !ft_isspace(lexer->c) && lexer->c != '\0')
		val = after_quotes(lexer, val);
	return (init_token(WORD, val));
}

char	*continue_quotes(t_lexer *lexer, char c)
{
	char	*val;
	char	*s;

	val = malloc(sizeof(char));
	val[0] = '\0';
	l_advance(lexer);
	while (lexer->c != c && lexer->c != '\0')
	{
		if (lexer->c == '$' && c == '\"')
		{
			s = expand_in_q(lexer);
			l_retreat(lexer);
		}
		else
			s = l_char_str(lexer);
		val = ft_strjoin(val, s);
		l_advance(lexer);
	}
	l_advance(lexer);
	if (!is_operator(lexer->c) && !ft_isspace(lexer->c) && lexer->c != '\0')
		val = after_quotes(lexer, val);
	return (val);
}

char	*continue_word(t_lexer *lexer)
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
			s = expand_in_q(lexer);
			l_retreat(lexer);
		}
		else
			s = l_char_str(lexer);
		val = ft_strjoin(val, s);
		l_advance(lexer);
	}
	if (val[0] == '\0')
		return ((char *)free_retnull(val));
	return (val);
}
