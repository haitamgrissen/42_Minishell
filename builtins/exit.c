/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:42:08 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 21:58:13 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
