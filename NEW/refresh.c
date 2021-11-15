/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:12:40 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 00:15:16 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "new_parser.h"

void	refresh_bash(void)
{
	g_exe.lexer_err = 0;
	if (g_exe.line)
		free(g_exe.line);
	g_exe.line = NULL;
	g_exe.cmd = NULL;//free commands and everything inside them (cmds args rdr)
}