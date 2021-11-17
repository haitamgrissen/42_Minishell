/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:39:45 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 22:33:54 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_pwds(void)
{
	t_envs	*oldnode;
	t_envs	*currentnode;
	char	*pwd;

	oldnode = getenv_node("OLDPWD");
	currentnode = getenv_node("PWD");
	if (oldnode && oldnode->val != NULL)
		free(oldnode->val);
	if (oldnode)
		oldnode->val = ft_strdup(currentnode->val);
	if (currentnode && currentnode->val != NULL)
		free(currentnode->val);
	if (currentnode)
	{
		pwd = (char *)malloc(sizeof(char) * 100);
		getcwd(pwd, 100);
		currentnode->val = pwd;
	}
}

void	cd(t_cmd *cmd)
{
	char	*path;
	t_envs	*env;

	if (cmd->args[1])
		path = ft_strdup(cmd->args[1]);
	else
	{
		env = getenv_node("HOME");
		path = ft_strdup(env->val);
	}
	if (chdir(path))
	{
		ft_putstr_fd(path, 2);
		perror(": ");
		g_exe.exite_err = 1;
	}
	else
		update_pwds();
	free(path);
}
