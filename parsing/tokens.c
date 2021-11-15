/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:47:51 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 21:59:03 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tokens(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

t_token	*free_retnull(char	*val)
{
	free(val);
	return (NULL);
}

int	token_tab_len(t_token **o)
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

t_token	**realloc_tokens(t_token **current, t_token *to_add)
{
	t_token	**ret;
	int		i;
	int		current_len;

	current_len = token_tab_len(current);
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
