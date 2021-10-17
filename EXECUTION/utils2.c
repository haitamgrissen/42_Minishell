/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:14:22 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/17 17:33:37 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"


int		ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}