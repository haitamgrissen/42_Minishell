/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:55:20 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 21:58:44 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tab_len(char **o)
{
	int	i;

	i = 0;
	if (o)
	{
		while (o[i] != NULL)
			i++;
	}
	return (i);
}

char	**realloc_args(char	**current, char *to_add)
{
	char	**ret;
	int		i;
	int		current_len;

	if (to_add[0] == ' ' && to_add[1] == '\0')
		return (current);
	current_len = tab_len(current);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (current_len + 2));
	while (i < current_len)
	{
		ret[i] = current[i];
		i++;
	}
	free(current);
	ret[i++] = ft_strdup(to_add);
	ret[i] = NULL;
	return (ret);
}

t_cmd	*init_cmds(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->args_count = 0;
	cmd->rdr = NULL;
	cmd->next = NULL;
	g_exe.cmd = cmd;
	return (cmd);
}

t_cmd	*add_cmd_node(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->cmd = NULL;
	new->args = NULL;
	new->args_count = 0;
	new->rdr = NULL;
	new->next = NULL;
	return (new);
}

void	token_to_cmd(t_token **tokens, t_cmd *cur_cmd, int i)
{
	if (tokens[i]->type == WORD)
	{
		if (cur_cmd->args == NULL)
			cur_cmd->cmd = ft_strdup(tokens[i]->value);
		cur_cmd->args = realloc_args(cur_cmd->args, tokens[i]->value);
	}
	else if (tokens[i]->type == IN || tokens[i]->type == OUT
		|| tokens[i]->type == APND || tokens[i]->type == HERDOC)
	{
		if (cur_cmd->rdr == NULL)
			cur_cmd->rdr = init_rdr(tokens[i + 1]->value, tokens[i]->type);
		else
			add_rdr_node(cur_cmd->rdr, tokens[i + 1]->value, tokens[i]->type);
	}
}
