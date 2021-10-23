/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:06:05 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/22 21:06:43 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/builtins.h"

char	*env_index(int index)
{
	t_envs	*current;
	char	*str;
	int		i;

	current = g_exe.envs;
	i = 0;
	while (current->next != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	if (current->val != NULL)
	{
		str = ft_strjoin(ft_strdup(current->key), ft_strdup("="));
		return (ft_strjoin(str, ft_strdup(current->val)));
	}
	else
		return (ft_strdup(current->key));
}

int	env_len(void)
{
	t_envs	*current;
	int		i;

	current = g_exe.envs;
	i = 0;
	while (current->next != NULL)
	{
		i++;
		current = current->next;
	}
	return (++i);
}

char	**env_to_arr(void)
{
	char	**ret;
	int		size;
	int		i;

	size = env_len();
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		ret[i] = env_index(i);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
