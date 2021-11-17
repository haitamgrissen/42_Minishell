/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:40:34 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/17 05:25:24 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_ve(t_cmd *cmd)
{
	char	*str;

	str = get_working_path(cmd->cmd);
	if (str)
	{
		check_exec(str);
		execve(str, cmd->args, g_exe.envs_arr);
		perror(str);
		write(2, "\n", 1);
		exit(126);
	}
	else
	{
		if (errno == 13)
		{
			perror("");
			exit(126);
		}
		write(2, cmd->cmd, ft_strlen(cmd->cmd));
		ft_putstr_fd(": command not found\n", 2);
	}
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

void	waiting_sigs(t_pipes *p)
{
	g_exe.pids_sig = 42;
	waitpid(p->last_pid, &p->laststat, 0);
	while (waitpid(-1, &p->status, 0) > 0)
		;
	if (WIFEXITED(p->laststat))
		g_exe.exite_err = WEXITSTATUS(p->laststat);
	else if (WIFSIGNALED(p->laststat))
	{
		if (WTERMSIG(p->laststat) == SIGQUIT)
			ft_putstr_fd("\\Quit: 3", 2);
		g_exe.exite_err = WTERMSIG(p->laststat) + 128;
	}
	g_exe.pids_sig = 0;
}

void	pipe_it(t_cmd *cmd)
{
	t_cmd	*current;
	t_pipes	p;
	int		i;

	p.p_in = dup(0);
	p.p_out = dup(1);
	i = 1;
	current = cmd;
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

int	execute_pipe(t_cmd *cmd)
{
	herdocs(cmd);
	if (!cmd->next && is_builtin(cmd->cmd))
		simple_cmd(cmd);
	else
		pipe_it(cmd);
	close_herdocs(cmd);
	return (0);
}
