/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:40:34 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/04 08:04:55 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/execution.h"


// void	exec_child(t_cmd *tmp)
// {
// 	if (tmp->args == NULL)
// 		exit(0);
// 	if (contain_slaches(tmp->args[0]) == 0)
// 	{
// 		if (isbuilt_in(tmp->args[0]))
// 			exit(exec_builtin(tmp));
// 		search_execute(tmp, g_exe.envs_arr);
// 	}
// 	if (tmp->args[0] != NULL)
// 		execve(tmp->args[0], tmp->args, g_exe.envs_arr);
// 	execve_error();
// }

// int	fork_and_execute(t_cmd *cmd, int *fd)
// {
// 	int		i;
// 	int		in;
// 	t_cmd	*tmp;
// 	int		pid;

// 	i = 0;
// 	in = 0;
// 	tmp = cmd;
// 	while (tmp != NULL)
// 	{
// 		pipe(fd);
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			redirect_std_in_out(tmp, i, in, fd);
// 			exec_child(tmp);
// 		}
// 		close(fd[1]);
// 		if (i > 0)
// 			close(in);
// 		in = fd[0];
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (pid);
// }

// int	exec_nested_cmd(t_cmd *cmd)
// {
// 	int		*fd;
// 	int		status;
// 	pid_t	pid;

// 	status = 0;
// 	fd = (int *)malloc(sizeof(int) * 2);
// 	pid = fork_and_execute(cmd, fd);
// 	waitpid(pid, &status, 0);
// 	while (wait(NULL) > 0)
// 		;
// 	free(fd);
// 	return (0);//get exit status
// }


// int	execute_pipe(t_cmd *cmd)
// {
// 	t_cmd	*current;

// 	current = cmd;
// 	while (current->next != NULL)
// 	{
// 		printf("%s\n", current->cmd);
// 		current = current->next;
// 	}
// 	printf("%s\n", current->cmd);

// 	return 0;
// 	// int		fd[2];
// 	// pid_t	pid;
// 	// int		sta;
// 	// t_cmd	*current;

// 	// current = cmd;
// 	// while (cmd->next != NULL)
// 	// {
// 	// 	pid = fork();
// 	// 	if (pid == 0)
// 	// 	{
// 	// 		dup2(fd[1], 0);
// 	// 		execute_child(cmd);
// 	// 	}
// 	// 	current = current->next;
// 	// }
// 	// pid = fork();
// 	// if (pid == 0)
// 	// {
// 	// 	dup2(fd[1], 0);
// 	// 	execute_child(cmd);
// 	// }
// 	// else
// 	// 	waitpid(pid, NULL, 0);
// 	// return 0;
// }
