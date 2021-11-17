/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:37:17 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/17 02:26:36 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_exec(char *string)
{
	struct stat	buf;

	stat(string, &buf);
	if (buf.st_mode & S_IFDIR)
	{
		dprintf(2, "%s: is directory\n", string);
		exit(126);
	}
}

void	execute_cmd(t_cmd *cmd)
{
	char	*str;

	if (cmd == NULL)
		exit(0);
	if (is_builtin(cmd->cmd))
		execute_builtin(cmd);
	else
	{
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
				exit (126);
			}
			write(2, cmd->cmd, ft_strlen(cmd->cmd));
			ft_putstr_fd(": command not found\n", 2);
		}
	}
	exit(127);
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

void	single_cmd(t_cmd *cmd, t_pipes *p)
{
	p->pid = fork();
	p->last_pid = p->pid;
	if (p->pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		redirect(cmd);
		execute_cmd(cmd);
	}
	close(p->p_in);
	close(p->p_out);
}

void	for_cmds(t_cmd *cmd, t_pipes *p)
{
	pipe(p->pipe_);
	close(p->p_out);
	p->p_out = p->pipe_[1];
	p->pid = fork();
	if (p->pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
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
	p->last_pid = p->pid;
	if (p->pid == 0)
	{
				signal(SIGQUIT, SIG_DFL);

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
