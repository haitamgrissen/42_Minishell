/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:02:06 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/14 20:54:20 by hgrissen         ###   ########.fr       */
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
			return (0);
		prev = curr;
		i++;
	}
	if (curr != WORD)
		return (0);
	return(1);
}
void	syntax_error(t_token **tokens)
{
	int	i;

	ft_putstr_fd("BASH: Syntax Error!\n", 2);
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	parse(t_lexer *lexer)
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
	while (tokens[i])
	{
		ft_putstr_fd(" | ", 1);
		ft_putstr_fd(tokens[i]->value, 1);
		ft_putstr_fd(" | ", 1);
		//free(tokens[i]);
		i++;
	}
	write(1, "\n", 1);
	if (analyze_syntax(tokens))
		ft_putstr_fd("good syntax\n", 2);// create_cmds(tokens);
	else
		ft_putstr_fd("syntax error\n", 2);//syntax_error(tokens);
}