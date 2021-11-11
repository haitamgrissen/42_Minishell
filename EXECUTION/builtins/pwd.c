/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:48:44 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/29 15:00:58 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/builtins.h"

void	pwd(void)
{
	char	*pwd;

	pwd = (char *)malloc(sizeof(char) * 100);
	printf("%s\n", getcwd(pwd, 100));
	free(pwd);
}
