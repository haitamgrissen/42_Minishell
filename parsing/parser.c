/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:02:06 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 20:26:48 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_cmds(t_token **tokens)
{
	t_cmd			*cmd_curr;
	int				i;

	g_exe.cmd = init_cmds();
	i = 0;
	cmd_curr = g_exe.cmd;
	while (tokens[i])
	{
		token_to_cmd(tokens, cmd_curr, i);
		if (tokens[i]->type == IN || tokens[i]->type == OUT
			|| tokens[i]->type == APND || tokens[i]->type == HERDOC)
			i++;
		if (tokens[i]->type == PIPE)
		{
			cmd_curr->next = add_cmd_node();
			cmd_curr = cmd_curr->next;
		}
		i++;
	}
}

int	check_ambigous_file(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->type != WORD && tokens[i]->type != PIPE
			&& tokens[i]->type != HERDOC)
		{
			if (ft_strchr(tokens[i + 1]->value, ' '))
				return (1);
			i++;
		}
		i++;
	}
	return (0);
}

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
		if (prev != WORD && i != 0 && curr != WORD
			&& prev != PIPE && curr != PIPE)
			return (0);
		if (i == 0 && curr == PIPE)
			return (0);
		prev = curr;
		i++;
	}
	if (curr != WORD)
		return (0);
	return (1);
}

void	syntax_error(int err)
{
	if (err == 1)
		ft_putstr_fd("BASH: Syntax Error!\n", 2);
	if (err == 2)
		ft_putstr_fd("BASH: Open Quotes!\n", 2);
	if (err == 3)
		ft_putstr_fd("BASH: Ambiguous Redirect!\n", 2);
}

void	parse(void)
{
	t_lexer	*lexer;
	t_token	**tokens;
	int		i;

	lexer = init_lexer(g_exe.line);
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
		syntax_error(1);
	else if (g_exe.lexer_err == 1)
		syntax_error(2);
	else if (check_ambigous_file(tokens))
		syntax_error(3);
	else
		create_cmds(tokens);
	free_tokens(tokens);
	free(lexer);
}
