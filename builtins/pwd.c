/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:48:44 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 23:42:24 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(void)
{
	char	*pwd;

	if (g_exe.ret)
		return ;
	pwd = (char *)malloc(sizeof(char) * 100);
	printf("%s\n", getcwd(pwd, 100));
	free(pwd);
	g_exe.exite_err = 0;
}
