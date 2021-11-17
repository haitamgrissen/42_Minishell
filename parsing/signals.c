/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:03:41 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 23:03:11 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cntl_c(int sig)
{
	int	i;

	i = sig;
	if (g_exe.pids_sig == 0)
	{
		g_exe.exite_err = 1;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		i = 0;
	}
}

void	catch_the_signal(void)
{
	signal(SIGINT, cntl_c);
	signal(SIGQUIT, SIG_IGN);
}
