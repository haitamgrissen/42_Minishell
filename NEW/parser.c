/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:02:06 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/13 14:21:23 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "new_parser.h"

t_token	**fill_tokens(t_token **src, t_token **dst, t_token *token)
{
	int	i;

	i = 0;
	while(src[i] != NULL)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = token;
	dst[i + 1] = NULL;
	return (dst);
}

t_token **parse(t_lexer *lexer)
{
	t_token **tokens;
	int		i;

	tokens = malloc(sizeof(struct s_tokens *) * 2);
	i = 0;
	tokens[0] = l_next_token(lexer);
	tokens[1] = NULL;
	while (tokens[i] != NULL)
	{
		i++;
		tokens = ft_reallocc(tokens, l_next_token(lexer));
	}
	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]->value);
		printf("%d\n", tokens[i]->type);
		i++;
	}
	return (tokens);
}