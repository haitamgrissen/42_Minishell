/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:44:42 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 21:25:20 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	printbyindex(t_envs *head, int index)
{
	t_envs	*current;
	int		i;

	current = head;
	i = 0;
	while (current->next != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	if (i < index)
		printf("this is the last node\n");
	if (current->val != NULL)
		printf("%s=%s\n", current->key, current->val);
	if (current->val == NULL)
		printf("NULL\n");
}

void	free_envs(t_envs	**head)
{
	t_envs	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->prev->key != NULL)
			free(tmp->prev->key);
		if (tmp->prev->val != NULL)
			free(tmp->prev->val);
		if (tmp->prev != NULL)
			free(tmp->prev);
	}
	if (tmp->key != NULL)
		free(tmp->key);
	if (tmp->val != NULL)
		free(tmp->val);
	if (tmp != NULL)
		free(tmp);
}

int	is_builtin(char *str)
{
	if (str)
	{
		if (!ft_strcmp(str, "echo"))
			return (1);
		if (!ft_strcmp(str, "cd"))
			return (1);
		if (!ft_strcmp(str, "pwd"))
			return (1);
		if (!ft_strcmp(str, "env"))
			return (1);
		if (!ft_strcmp(str, "export"))
			return (1);
		if (!ft_strcmp(str, "unset"))
			return (1);
		if (!ft_strcmp(str, "exit"))
			return (1);
	}
	return (0);
}

void	execute_builtin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->cmd, ECHO))
		echo(cmd);
	else if (!ft_strcmp(cmd->cmd, CD))
		cd(cmd);
	else if (!ft_strcmp(cmd->cmd, PWD))
		pwd();
	else if (!ft_strcmp(cmd->cmd, ENV))
		print_env();
	else if (!ft_strcmp(cmd->cmd, EXPORT))
		export(cmd);
	else if (!ft_strcmp(cmd->cmd, UNSET))
		unset(cmd);
	else if (!ft_strcmp(cmd->cmd, EXIT))
		exit_builtin(cmd);
}
