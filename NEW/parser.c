/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:02:06 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/13 02:26:29 by hgrissen         ###   ########.fr       */
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
	t_token **tmp;
	int		i;

	tokens = malloc(sizeof(struct s_tokens *) * 2);
	i = 0;
	tokens[0] = l_next_token(lexer);
	tokens[1] = NULL;
	while (tokens[i] != NULL)
	{
		i++;
		tmp = realloc(tokens, (i + 2) * sizeof(struct s_tokens*));
		tmp = fill_tokens(tokens, tmp, l_next_token(lexer));
		tokens = tmp;
	}
	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]->value);
		i++;
	}
	return (tokens);
}