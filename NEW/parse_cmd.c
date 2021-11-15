/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:55:20 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 04:46:11 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "new_parser.h"

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

	current_len = tab_len(current);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (current_len + 2));
	while (i < current_len)
	{
		ret[i] = current[i];
		i++;
	}
	free(current);
	ret[i++] = to_add;
	ret[i] = NULL;
	return (ret);
}

t_cmd	*init_cmds()
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

t_cmd	*add_cmd_node()
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

t_redirection	*init_rdr(char *value, t_types type)
{
	t_redirection	*rdr;

	rdr = (t_redirection *)malloc(sizeof(t_redirection));
	rdr->file = ft_strdup(value);
	rdr->type = type;//change diffrence betwwen parsing and execution
	rdr->next = NULL;
	return (rdr);
}
void	add_rdr_node(t_redirection *head, char *val, t_types type)
{
	t_redirection	*curr;
	t_redirection	*new;

	curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	new = (t_redirection *)malloc(sizeof(t_redirection));
	new->file = ft_strdup(val);
	new->type = type;//change diffrence betwwen parsing and execution
	new->next = NULL;
}

void print_Test()
{
	int 			i;
	t_cmd			*cur_cmd;
	t_redirection	*cur_rdr;
	

	cur_cmd = g_exe.cmd;
	while (cur_cmd)
	{
		i = 0;
		cur_rdr = cur_cmd->rdr;
		if (cur_cmd->cmd != NULL)
			printf("\nCOMMAND : %s\n", cur_cmd->cmd);
		printf("\nARGS : ");
		while (cur_cmd->args != NULL && cur_cmd->args[i])
		{
			printf("%s ", cur_cmd->args[i]);
			i++;
		}
		printf("\nRDRS : \n");
		while (cur_rdr)
		{
			printf("type: %d      file: %s\n", cur_cmd->rdr->type, cur_cmd->rdr->file);
			cur_rdr = cur_rdr->next;
		}
		
		cur_cmd = cur_cmd->next;
	}
}

void	create_cmds(t_token **tokens)
{
	t_cmd			*cmd_head;
	t_cmd			*cmd_curr;
	t_redirection	*rdr_head;
	int				i;

	cmd_head = init_cmds();
	i = 0;
	cmd_curr = cmd_head;
	g_exe.cmd = cmd_head;
	while (tokens[i])
	{
		if (tokens[i]->type == WORD)
		{
			if (cmd_curr->args == NULL)
				cmd_curr->cmd = ft_strdup(tokens[i]->value);
			cmd_curr->args = realloc_args(cmd_curr->args, tokens[i]->value);
		}
		if (tokens[i]->type == IN || tokens[i]->type == OUT 
			|| tokens[i]->type == APND || tokens[i]->type == HERDOC)
		{
			if (cmd_curr->rdr == NULL)
				cmd_curr->rdr = init_rdr(tokens[i + 1]->value, tokens[i]->type);
			else
				add_rdr_node(cmd_curr->rdr, tokens[i + 1]->value, tokens[i]->type);
			i++;
		}
		if (tokens[i]->type == PIPE)
		{
			cmd_curr->next = add_cmd_node();
			cmd_curr = cmd_curr->next;
			rdr_head = NULL;
			i++;
			break;
		}
		i++;
	}
	print_Test();
}
