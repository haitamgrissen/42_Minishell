/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:42:08 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/17 04:12:13 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	err_exites(char *arg, int i, int has, int first);

int	str_isdigits(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

void	exit_builtin(t_cmd	*cmd)
{
	int	i;
	int	hasalpha;
	int	f_is_alpha;

	i = 0;
	hasalpha = 0;
	f_is_alpha = 0;
	while (cmd->args[++i])
	{
		if (i == 1 && str_isdigits(cmd->args[i]) == 0)
			f_is_alpha = 1;
		if (str_isdigits(cmd->args[i]) == 0)
			hasalpha = 1;
	}
	err_exites(cmd->args[1], i, hasalpha, f_is_alpha);
}

void	err_exites(char *arg, int i, int has, int first)
{
	if (i == 2 && has == 0)
		exit((unsigned char)atoi(arg));
	if (i == 1 && has == 0)
		exit(g_exe.exite_err);
	ft_putstr_fd("bash: exit", 2);
	if (i >= 2 && first)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	if (i > 2 && first == 0)
	{
		ft_putstr_fd(": too many arguments\n", 2);
		g_exe.exite_err = 1;
	}
}
