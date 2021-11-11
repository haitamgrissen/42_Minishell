/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:07:47 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/08 12:08:34 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		outtil(int fd, char **rest, char **line)
{
	char *tmp;

	if (BUFFER_SIZE < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	*line = ft_strdup("");
	if (rest[fd] != '\0')
	{
		if (!kayn_ster(rest[fd]))
		{
			*line = ft_strjoin(*line, rest[fd]);
			rest[fd] = NULL;
		}
		else
		{
			*line = ft_strjoin(*line, ft_substr(rest[fd], 0,
				kayn_ster(rest[fd]) - rest[fd]));
			tmp = rest[fd];
			rest[fd] = ft_strdup(&rest[fd][kayn_ster(rest[fd]) - rest[fd] + 1]);
			free(tmp);
			return (1);
		}
	}
	return (2);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	char		*str;
	static char	*rest[1024];

	i = 0;
	if ((i = outtil(fd, rest, line)) < 2)
		return (i);
	str = (char *)malloc(BUFFER_SIZE + 1);
	while ((i = read(fd, str, BUFFER_SIZE)))
	{
		str[i] = '\0';
		if (!kayn_ster(str))
			*line = ft_strjoin(*line, str);
		else
		{
			*line = ft_strjoin(*line, ft_substr(str, 0, kayn_ster(str) - str));
			rest[fd] = ft_strdup(&str[kayn_ster(str) - str + 1]);
			free(str);
			return (1);
		}
		str = (char*)malloc(BUFFER_SIZE + 1);
	}
	free(str);
	return (0);
}