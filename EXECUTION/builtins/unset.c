/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:05:18 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/21 13:24:50 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/builtins.h"

void	remove_node(t_envs **head, char	*key)
{
	t_envs	*tmp;

	tmp = getenv_node(key);
	if (tmp)
	{
		if (tmp->prev == NULL)
		{
			tmp->next->prev = NULL;
			*head = (tmp)->next;
		}
		else if (tmp->next == NULL)
		{
			tmp->prev->next = NULL;
		}
		else
		{
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
		}
		free(tmp->key);
		if (tmp->val != NULL)
			free(tmp->val);
		free(tmp);
	}
}

void	unset(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		remove_node(&g_exe.envs, cmd->args[i]);
		i++;
	}
}
