/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:15:40 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 21:57:46 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_paths(void)
{
	t_envs	*node;
	char	**paths;

	node = getenv_node("PATH");
	if (!node)
		return (NULL);
	paths = ft_split(node->val, ':');
	return (paths);
}

char	*free_paths(char **paths, char *str, int ret)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	if (str && ret == 0)
	{
		free(str);
		return (NULL);
	}
	else if (str && ret == 1)
		return (str);
	else
		return (NULL);
}

char	*join_command(char	*str, char *command, char *path)
{
	str = ft_strdup(path);
	str = ft_strjoin(str, ft_strdup("/"));
	str = ft_strjoin(str, ft_strdup(command));
	return (str);
}

char	*get_working_path(char	*command)
{
	char	*str;
	char	**paths;
	int		ret;
	int		i;

	paths = get_paths();
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		str = join_command(str, command, paths[i]);
		ret = open(str, O_RDONLY);
		if (ret != -1)
			return (free_paths(paths, str, 1));
		free(str);
	}
	str = ft_strdup(command);
	ret = open(str, O_RDONLY);
	if (ret != -1)
		return (free_paths(paths, str, 1));
	else
		return (free_paths(paths, str, 0));
}
