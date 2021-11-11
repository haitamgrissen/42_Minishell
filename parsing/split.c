/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:00:41 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/09 16:00:51 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	c_w(char const *str, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
		{
			i++;
		}
		if (str[i] != c && str[i] != '\0')
			j++;
		while (str[i] != c && (str[i] != '\0'))
			i++;
	}
	return (j);
}

static char	**freee(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	s_p(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static int	len_str(char const *s, int i, char c)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_split(char *s, char c)
{
	char	**cpy;
	int		len;
	int		k;
	int		i;
	int		start;

	k = -1;
	i = 0;
	if (!s || !(cpy = (char**)malloc(sizeof(char*) * (c_w(s, c) + 1))))
		return (0);
	while (s[i])
	{
		len = 0;
		i += s_p(&s[i], c);
		start = i;
		len = len_str(s, i, c);
		i += len;
		if (len)
			if (!(cpy[++k] = ft_substr(s, start, len)))
				return (freee(cpy));
	}
	cpy[++k] = 0;
	return (cpy);
}