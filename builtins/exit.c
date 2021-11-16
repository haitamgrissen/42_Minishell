/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:42:08 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 21:38:10 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_statuses(void)
{
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 1);
}

void	exit_builtin(t_cmd	*cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	if (i == 1)
		exit(g_exe.ret);
	else if (i == 2)
		exit(atoi(cmd->args[1]));
}
