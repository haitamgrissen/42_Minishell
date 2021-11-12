/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:39:45 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/11 22:07:43 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/builtins.h"

void	update_pwds(char *newpwd)
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
		printf("%s: Not a directory\n", path);
	else
		update_pwds(path);
	free(path);
}
