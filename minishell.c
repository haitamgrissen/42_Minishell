/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:39:02 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 21:19:38 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_lexer	*lexer;

	init_envs(env);
	refresh_bash();
	while (TRUE)
	{
		catch_the_signal();
		g_exe.line = readline("BASH$>: ");
		if (!g_exe.line)
		{
			ft_putstr_fd("exit\n", 1);
			return (0);
		}
		if (g_exe.line[0] == '\0')
			continue ;
		add_history(g_exe.line);
		lexer = init_lexer(g_exe.line);
		parse(lexer);
		execute_pipe(g_exe.cmd);
		free(lexer);
		refresh_bash();
	}
	return (0);
}