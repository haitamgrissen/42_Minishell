/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:46:05 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/11 03:20:08 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/wait.h>
# include  <sys/errno.h>

# include <readline/readline.h>
# include <readline/history.h>
typedef struct s_envs
{
	char			*key;
	char			*val;
	struct s_envs	*next;
	struct s_envs	*prev;
}					t_envs;

typedef struct s_pipes
{
	int		pid;
	int		pipe_[2];
	int		p_in;
	int		p_out;
	int		status;
}			t_pipes;

# define RDRIN 1
# define RDROUT 2
# define APPEND 3
# define HEREDOC 4

typedef struct s_redirection
{
	int						type;
	char					*file;
	int						index;
	int						fd;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	int				args_count;
	t_redirection	*rdr;
	struct s_cmd	*next;
}					t_cmd;

/*
	global execution structure that holds all data to be
	accessed easily from anywhere!!!
*/
typedef struct s_exe
{
	t_cmd			*cmd;
	t_envs			*envs_list;
	char			**envs_arr;
	int				pipe_count;
	int				ret;
	int				exite_err;
}					t_exe;

t_exe				g_exe;

/*
	helper functions and utilities (might be removed from here)
*/
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
int			ft_strlen(char *s);
char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
char		*ft_itoa(int n);
void		ft_putstr_fd(char *s, int fd);

char		*get_working_path(char	*command);



int		execute_pipe(t_cmd *cmd);
void	execute_cmd(t_cmd *cmd);


void	redirect(t_cmd *cmd, t_pipes *p);
#endif