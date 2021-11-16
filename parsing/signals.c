/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:03:41 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 18:17:42 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cntl_c(int sig)
{
	int	i;

	i = sig;
	g_exe.exite_err = 1;
	ft_putstr_fd("BASH$>:\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	i = 0;
}

void	cntl_slash(int sig)
{
	char	*str;

	str = NULL;
	str = ft_itoa(sig);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	g_exe.exite_err = 131;
	free(str);
}

void	catch_the_signal(void)
{
	g_exe.exite_err = 0;
	signal(SIGINT, cntl_c);
	signal(SIGQUIT, SIG_IGN);
}
