/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:20:41 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/19 11:10:23 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/builtins.h"

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

void	echo(t_cmd	*cmd)
{
	int	rm_nl;
	int	printed;
	int	i;

	rm_nl = 0;
	printed = 0;
	i = 0;
	while (cmd->args[i])
	{
		if (printed == 0)
		{
			if (is_rmnl(cmd->args[i]))
				rm_nl = 1;
			else
			{
				printed = 1;
				printf("%s", cmd->args[i]);
			}
		}
		else
			printf(" %s", cmd->args[i]);
		i++;
	}
	if (rm_nl == 0)
		printf("\n");
}
