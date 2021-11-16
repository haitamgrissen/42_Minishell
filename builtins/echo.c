/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:20:41 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 17:36:08 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_rmnl(char *str)
{
	int	i;

	if (str[0] == '-' && str[1] == 'n')
	{
		i = 2;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

void	check_print(char *args, int *rm_nl, int *printed)
{
	if (*printed == 0)
	{
		if (is_rmnl(args))
			*rm_nl = 1;
		else
		{
			*printed = 1;
			ft_putstr_fd(args, 1);
		}
	}
	else
	{
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(args, 1);
	}
}

void	echo(t_cmd	*cmd)
{
	int	rm_nl;
	int	printed;
	int	i;

	rm_nl = 0;
	printed = 0;
	i = 1;
	while (cmd->args[i])
	{
		check_print(cmd->args[i], &rm_nl, &printed);
		i++;
	}
	if (rm_nl == 0)
		ft_putstr_fd("\n", 1);
}
