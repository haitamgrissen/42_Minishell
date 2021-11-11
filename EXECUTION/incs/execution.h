/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:01:03 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/10 22:01:04 by sel-fcht         ###   ########.fr       */
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

# define RDRIN 1 // < // ls -al | cat > file1 > file2 >> file3 << ok
# define RDROUT 2 // >
# define APPEND 3 // >>
# define HEREDOC 4 // << 

typedef struct s_redirection
{
	int						type;
	int						position;
	char					*file;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_cmd
{
	char			*cmd;
	char 			**tokens;
	char			**red;
	char			**args; //args[0] = ls args[1] -al args[2] = |
	int				args_count;
	//t_redirection	*rdr;
	struct s_redirection rdr;
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
char		*get_working_path(char	*command);



int		execute_pipe(t_cmd *cmd);
void	execute_cmd(t_cmd *cmd);
#endif