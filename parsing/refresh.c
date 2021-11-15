/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:12:40 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 22:02:51 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_rdr(t_redirection *rdr)
{
	t_redirection	*cur;
	t_redirection	*tmp;

	cur = rdr;
	while (cur)
	{
		free(cur->file);
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

void	free_cmd(void)
{
	t_cmd	*cur;
	t_cmd	*tmp;
	int		i;

	if (g_exe.cmd == NULL)
		return ;
	cur = g_exe.cmd;
	while (cur)
	{
		if (cur->cmd)
			free(cur->cmd);
		i = 0;
		while (cur->args && cur->args[i])
		{
			free(cur->args[i]);
			i++;
		}
		if (cur->args)
			free(cur->args);
		free_rdr(cur->rdr);
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

void	refresh_bash(void)
{
	g_exe.lexer_err = 0;
	if (g_exe.line)
		free(g_exe.line);
	free_cmd();
	g_exe.line = NULL;
	g_exe.cmd = NULL;
}
