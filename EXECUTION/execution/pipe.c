/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:40:34 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/11 04:02:22 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/execution.h"

void	for_cmds(t_cmd *cmd, t_pipes *p)
{
	pipe(p->pipe_);
	p->p_out = p->pipe_[1];
	p->pid = fork();
	if (p->pid == 0)
	{
		dup2(p->p_out, 1);
		close(p->pipe_[1]);
		dup2(p->p_in, 0);
		close(p->pipe_[0]);
		redirect(cmd, p);
		execute_cmd(cmd);
	}
	if (p->p_in > 2)
		close(p->p_in);
	p->p_in = p->pipe_[0];
	close(p->p_out);
}

void	last_cmd(t_cmd *cmd, t_pipes *p)
{
	p->pid = fork();
	if (p->pid == 0)
	{
		dup2(p->p_in, 0);
		if (p->p_in != 0)
			close(p->p_in);
		redirect(cmd, p);
		execute_cmd(cmd);
	}
	if (p->pipe_[1] != 1)
		close(p->pipe_[1]);
	if (p->p_in != 0)
		close(p->p_in);
}

void	_cmd(t_cmd *cmd, t_pipes *p)
{
	redirect(cmd, p);
	execute_cmd(cmd);
}

int	execute_pipe(t_cmd *cmd)
{
	t_cmd	*current;
	t_pipes	p;

	p.p_in = dup(0);
	p.p_out = dup(1);
	current = cmd;
	while (current)
	{
		if (current->next)
			for_cmds(current, &p);
		else
			last_cmd(current, &p);
		current = current->next;
	}
	while (waitpid(-1, &p.status, 0) > 0)
		;
	return (0);
}
