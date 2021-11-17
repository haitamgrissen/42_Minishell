/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:03:06 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 22:30:15 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(void)
{
	t_envs	*current;

	current = g_exe.envs_list;
	while (current && current->next)
	{
		if (current->val == NULL)
			printf("declare -x %s\n", current->key);
		else
			printf("declare -x %s=\"%s\"\n", current->key, current->val);
		current = current->next;
	}
	if (current && current->val == NULL)
		printf("declare -x %s\n", current->key);
	else if (current && current->val)
		printf("declare -x %s=\"%s\"\n", current->key, current->val);
}

int	update_node(char	*str)
{
	t_envs	*tmp;
	char	*tmp_key;
	int		i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	tmp_key = ft_substr(str, 0, i);
	tmp = getenv_node(tmp_key);
	if (tmp != NULL)
	{
		free(tmp->key);
		if (tmp->val != NULL)
			free(tmp->val);
		split_env(ft_strdup(str), &tmp->key, &tmp->val);
		free(tmp_key);
		return (1);
	}
	free(tmp_key);
	return (0);
}

void	add_node(t_envs *head, char	*str)
{
	t_envs	*current;
	t_envs	*new;

	if (!check_key_err(str))
	{
		write(2, "not a valid identifier\n", 23);
		g_exe.exite_err = 1;
		return ;
	}
	current = head;
	if (update_node(str) == 1)
		return ;
	while (current->next != NULL)
		current = current->next;
	new = (t_envs *)malloc(sizeof(t_envs));
	current->next = new;
	new->key = NULL;
	new->val = NULL;
	split_env(ft_strdup(str), &new->key, &new->val);
	new->next = NULL;
	new->prev = current;
}

void	export(t_cmd *cmd)
{
	int	i;

	if (cmd->args[1] == NULL)
		print_export();
	i = 1;
	while (cmd->args[i])
	{
		add_node(g_exe.envs_list, cmd->args[i]);
		free_env_arr(g_exe.envs_arr);
		g_exe.envs_arr = env_to_arr();
		i++;
	}
}
