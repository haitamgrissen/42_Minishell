/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exapnsion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:00:58 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/11 10:33:58 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incs/builtins.h"

char	*getenv_val(char *key)
{
	t_envs	*node;

	node = getenv_node(key);
	if (node != NULL)
		return (ft_strdup(node->val));
	else
		return (NULL);
}

