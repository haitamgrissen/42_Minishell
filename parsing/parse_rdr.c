/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:00:34 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 21:58:47 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_redirection	*init_rdr(char *value, t_types type)
{
	t_redirection	*rdr;

	rdr = (t_redirection *)malloc(sizeof(t_redirection));
	rdr->file = ft_strdup(value);
	rdr->type = type;
	rdr->next = NULL;
	return (rdr);
}

void	add_rdr_node(t_redirection *head, char *val, t_types type)
{
	t_redirection	*curr;
	t_redirection	*new;

	curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	new = (t_redirection *)malloc(sizeof(t_redirection));
	new->file = ft_strdup(val);
	new->type = type;
	new->next = NULL;
	curr->next = new;
}

int	is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}
