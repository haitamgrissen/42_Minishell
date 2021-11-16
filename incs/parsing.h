/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:24:11 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/16 18:26:07 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell.h"
# include "execution.h"

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

int				ft_isspace(int c);

t_token			*init_token(int type, char *value);

t_lexer			*init_lexer(char *contents);
void			l_advance(t_lexer *lexer);
void			l_retreat(t_lexer *lexer);
void			l_skip_white(t_lexer *lexer);
t_token			*l_next_token(t_lexer *lexer);
t_token			*l_collect_string(t_lexer *lexer, char c);
t_token			*l_collect_wd(t_lexer *lexer);
t_token			*l_adv_token(t_lexer *lexer, t_token *token);
char			*l_char_str(t_lexer *lexer);
t_token			*switch_token(t_lexer *lexer);

char			*continue_word(t_lexer *lexer);
char			*continue_quotes(t_lexer *lexer, char c);

void			*ft_realloc(void *ptr, size_t newsize);

int				is_operator(char c);
void			parse(void);

t_token			*expand_token(t_lexer *lexer);

t_token			**realloc_tokens(t_token **current, t_token *to_add);

char			*get_exp_word(t_lexer *lexer);
char			*expand_exit_error(t_lexer *lexer);
t_token			*open_quotes_err(char *val);
/*
	signals
*/

void			catch_the_signal(void);
void			cntl_slash(int sig);
void			cntl_c(int sig);

char			*after_quotes(t_lexer *lexer, char *val);
t_token			*free_retnull(char	*val);

char			*get_env_val(char *key);

void			create_cmds(t_token **tokens);

void			refresh_bash(void);

void			free_tokens(t_token **tokens);

t_redirection	*init_rdr(char *value, t_types type);
void			add_rdr_node(t_redirection *head, char *val, t_types type);

char			*ft_strchr(const char *str, int c);

t_cmd			*init_cmds(void);
void			token_to_cmd(t_token **tokens, t_cmd *cur_cmd, int i);
t_cmd			*add_cmd_node(void);

#endif