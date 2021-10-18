/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:39:45 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/18 15:42:44 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/execution.h"

void	cd(t_cmd *cmd)
{
	char	*path;

	printf("%d\n", cmd->args_count);
	if (cmd->args_count)
		path = ft_strdup(cmd->args[0]);
	else
		path = ft_strdup(getenv("HOME"));// change getenv with my getenv
	if (chdir(path))
		printf("%s: Not a directory\n", path);
	free(path);
}
