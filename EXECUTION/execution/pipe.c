/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:40:34 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/12 04:09:25 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/execution.h"

void	for_cmds(t_cmd *cmd, t_pipes *p)
{
	pipe(p->pipe_);
	close(p->p_out);
	p->p_out = p->pipe_[1];
	p->pid = fork();
	if (p->pid == 0)
	{
		dup2(p->p_out, 1);
		close(p->pipe_[1]);
		dup2(p->p_in, 0);
		close(p->pipe_[0]);
		redirect(cmd);
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
		if (p->p_in != 0)
			dup2(p->p_in, 0);
		if (p->p_in != 0)
			close(p->p_in);
		redirect(cmd);
		execute_cmd(cmd);
	}
	if (p->pipe_[1] != 1)
		close(p->pipe_[1]);
	if (p->p_in != 0)
		close(p->p_in);
}

void	single_cmd(t_cmd *cmd, t_pipes *p)
{
	p->pid = fork();
	if (p->pid == 0)
	{
		redirect(cmd);
		execute_cmd(cmd);
	}
	close(p->p_in);
	close(p->p_out);
}
void	close_herdocs(t_cmd *cmd)
{
	t_cmd			*current;
	t_redirection	*cur_rdr;
	char			*f;

	current = cmd;
	while (current != NULL)
	{
		cur_rdr = current->rdr;
		while (cur_rdr != NULL)
		{
			if (cur_rdr->type == HEREDOC)
			{
				f = ft_strjoin(strdup("/tmp/file"), ft_itoa(cur_rdr->index));
				close(cur_rdr->fd);
				unlink(f);
				free(f);
			}
			cur_rdr = cur_rdr->next;
		}
		current = current->next;
	}
}

void	simple_cmd(t_cmd *cmd)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	redirect(cmd);
	execute_builtin(cmd);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void	waiting_sigs(t_pipes *p)
{
	while (waitpid(-1, &p->status, 0) > 0)
	{
		if (WIFEXITED(p->status))
			g_exe.ret = WEXITSTATUS(p->status);
		else if (WIFSIGNALED(p->status))
		{
			if (WTERMSIG(p->status) == SIGQUIT)
				ft_putstr_fd("\\Quit: 3", 2);
			g_exe.ret = WTERMSIG(p->status) + 128;
		}
	}
}

int	execute_pipe(t_cmd *cmd)
{
	t_cmd	*current;
	t_pipes	p;
	int		i;

	current = cmd;
	herdocs(cmd);
	if (!current->next && is_builtin(current->cmd))
		simple_cmd(cmd);
	else
	{
		p.p_in = dup(0);
		p.p_out = dup(1);
		i = 1;
		while (current)
		{
			if (i++ == 1 && current->next == NULL)
				single_cmd(current, &p);
			else
			{
				if (current->next)
					for_cmds(current, &p);
				else
					last_cmd(current, &p);
			}
			current = current->next;
		}
		waiting_sigs(&p);
	}
	close_herdocs(cmd);
	return (0);
}
