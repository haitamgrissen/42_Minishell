/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:02:06 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 04:49:16 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_parser.h"

int	analyze_syntax(t_token **tokens)
{
	t_types	prev;
	t_types	curr;
	int		i;

	i = 0;
	prev = -1;
	while (tokens[i])
	{
		curr = tokens[i]->type;
		if (prev != WORD && prev != -1 && curr != WORD && prev != PIPE && curr != PIPE)
			return (0);
		prev = curr;
		i++;
	}
	if (curr != WORD)
		return (0);
	return (1);
}

void	syntax_error(t_token **tokens, int err)
{
	if (err == 1)
		ft_putstr_fd("BASH: Syntax Error!\n", 2);
	if (err == 2)
		ft_putstr_fd("BASH: Open Quotes!\n", 2);
}

void	parse(t_lexer *lexer)
{
	t_token	**tokens;
	int		i;

	tokens = malloc(sizeof(struct s_tokens *) * 2);
	i = 0;
	tokens[0] = l_next_token(lexer);
	tokens[1] = NULL;
	while (tokens[i] != NULL)
	{
		i++;
		tokens = realloc_tokens(tokens, l_next_token(lexer));
	}
	if (!analyze_syntax(tokens))
		syntax_error(tokens, 1);
	else if (g_exe.lexer_err == 1)
		syntax_error(tokens, 2);
	else
		create_cmds(tokens);
	free_tokens(tokens);
}
