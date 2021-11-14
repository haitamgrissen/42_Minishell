/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:02:06 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/13 16:42:08 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "new_parser.h"

int	analyze_syntax(t_token **tokens)
{
	t_types	prev;
	t_types	curr;
	int		i;

	i = 0;
	prev = -1;
	while (tokens[i])
	{
		curr = tokens[i]->type;
		if (prev != WORD && prev != -1 && curr != WORD)
		{
			dprintf(2, "Syntax Error!\n");
			return (0);
		}
		prev = curr;
		i++;
	}
	if (curr != WORD)
	{
			dprintf(2, "Syntax Error!\n");
			return (0);
	}
	return(1);
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
		printf("%s ", tokens[i]->value);
		i++;
	}
	printf("\n");
	analyze_syntax(tokens);
	return (tokens);
}