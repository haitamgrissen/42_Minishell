/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:02:17 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/10 19:32:13 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	print_export()
{
	
}

void	print_env(t_envs	*envs)
{
	t_envs	*current;
	
	current = envs;
	while(current->next != NULL)
	{
		printf("%s=%s\n", current->bef_eq, current->aft_eq);
		current = current->next;
	}
}

void	split_env(char **f, char **bf, char **af)
{
	int		i;
	int		j;

	i = 0;
	if (!(*f))
		return ;
	while ((*f)[i] != '=')
		i++;
	(*bf) = ft_substr((*f), 0, i);
	j = 0;
	while ((*f)[i + j])
		j++;
	(*af) = ft_substr((*f), i + 1, j);
}

void	add_node(t_envs *head, char	*str)
{
	t_envs	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_envs *)malloc(sizeof(t_envs));
	current->full = ft_strdup(str);
	split_env(&current->full, &current->bef_eq, &current->aft_eq);
	current->next->next = NULL;
}

t_envs	*create_envs(char **env)
{
	t_envs	*ret;
	int		i;

	ret = (t_envs *)malloc(sizeof(t_envs));
	ret->full = ft_strdup(env[0]);
	split_env(&ret->full, &ret->bef_eq, &ret->aft_eq);
	ret->next = NULL;
	i = 0;
	while (env[i])
	{
		add_node(ret, env[i]);
		i++;
	}
	return (ret);
}
