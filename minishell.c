/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:39:02 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 18:32:52 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)av;
	init_envs(env);
	if (ac == 1)
	{
		while (TRUE)
		{
			refresh_bash();
			catch_the_signal();
			g_exe.line = readline("BASH$>: ");
			if (g_exe.line == NULL)
			{
				ft_putstr_fd("exit\n", 1);
				exit (0);
			}
			if (g_exe.line[0] == '\0')
				continue ;
			add_history(g_exe.line);
			parse();
			if (g_exe.cmd && g_exe.lexer_err == 0)
				execute_pipe(g_exe.cmd);
		}
	}
	return (0);
}
