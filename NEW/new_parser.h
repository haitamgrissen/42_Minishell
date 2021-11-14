/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:24:11 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/13 23:27:22 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_PARSER_H
# define NEW_PARSER_H

# include "../EXECUTION/incs/builtins.h"

typedef struct s_parser
{
	char	*line;
	char	**tab;

}		t_parser;

typedef enum e_types
{
	WORD,
	IN,
	OUT,
	APND,
	HERDOC,
	PIPE,
}	t_types;

typedef struct s_lexer
{
	char			c;
	char			*content;
	unsigned int	i;
}					t_lexer;

typedef struct s_token
{
	char		*value;
	t_types		type;
}				t_token;

int		ft_isspace(int c);

t_token	*init_token(int type, char *value);

t_lexer	*init_lexer(char *contents);
void	l_advance(t_lexer *lexer);
void	l_skip_white(t_lexer *lexer);
t_token	*l_next_token(t_lexer *lexer);
t_token	*l_collect_string(t_lexer *lexer, char c);
t_token	*l_collect_wd(t_lexer *lexer);
t_token	*l_adv_token(t_lexer *lexer, t_token *token);
char	*l_char_str(t_lexer *lexer);
t_token	*switch_token(t_lexer *lexer);

char	*continue_word(t_lexer *lexer);
char	*continue_quotes(t_lexer *lexer, char c);

void	*ft_realloc(void *ptr, size_t newsize);

int		is_operator(char c);
t_token	**parse(t_lexer *lexer);

t_token	*expand_token(t_lexer *lexer);

t_token	**ft_reallocc(t_token **current, t_token *to_add);

#endif