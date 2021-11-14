/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:47:51 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/13 23:23:33 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_parser.h"

int	tab_len(t_token **o)
{
	int	i;

	i = 0;
	if (o)
	{
		while (o[i] != NULL)
			i++;
	}
	return (i);
}

t_token	**ft_reallocc(t_token **current, t_token *to_add)
{
	t_token	**ret;
	int		i;
	int		current_len;

	current_len = tab_len(current);
	i = 0;
	ret = (t_token **)malloc(sizeof(t_token *) * (current_len + 2));
	while (i < current_len)
	{
		ret[i] = current[i];
		i++;
	}
	free(current);
	ret[i++] = to_add;
	ret[i] = NULL;
	return (ret);
}

t_token	*init_token(int type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(struct s_token));
	token->type = type;
	token->value = value;
	return (token);
}
