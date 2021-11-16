/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:44:26 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 16:04:37 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_str_new(size_t size)
{
	return ((char *)malloc(sizeof(char) * (size + 1)));
}

static int	ft_numlen(int n, int minus)
{
	int	numlen;

	numlen = 1;
	while (n)
	{
		n /= 10;
		numlen++;
	}
	return (numlen + minus);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;
	int		minus;
	int		digit;

	if (n < 0)
		minus = 1;
	else
		minus = 0;
	numlen = ft_numlen(n, minus);
	str = ft_str_new(numlen);
	if (str)
	{
		str[numlen--] = '\0';
		while (numlen >= minus)
		{
			digit = n % 10;
			str[numlen--] = (digit < 0 ? -digit : digit) + '0';
			n /= 10;
		}
		if (minus)
			str[0] = '-';
	}
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	char	sym;

	ptr = (char *)str;
	sym = (char)c;
	while (*ptr && !(*ptr == sym))
		ptr++;
	if (*ptr == sym)
		return (ptr);
	else
		return (NULL);
}
