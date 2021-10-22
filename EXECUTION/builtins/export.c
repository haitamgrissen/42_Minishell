/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:03:06 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/21 13:23:41 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/builtins.h"

void	print_export(void)
{
	t_envs	*current;

	current = g_exe.envs;
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

int	update_node(t_envs *head, char	*str)
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
		return ;
	current = head;
	if (update_node(head, str) == 1)
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

	i = 0;
	while (cmd->args[i])
	{
		add_node(g_exe.envs, cmd->args[i]);
		i++;
	}
}
