/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:49:26 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 22:01:28 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"
# include "execution.h"

# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXIT "exit"
# define UNSET "unset"
# define EXPORT "export"
# define ENV "env"

void		pwd(void);
void		cd(t_cmd *cmd);
void		echo(t_cmd	*cmd);

void		exit_builtin(t_cmd *cmd);

t_envs		*getenv_node(char *key);
/*
	enviroment and export and unset fuctions
	might be removed from here and added to another heaader file 
	containing BUILTINS functions
*/
void		init_envs(char **env);
void		add_node(t_envs *head, char	*str);
void		remove_node(t_envs **head, char	*key);
void		print_env(void);
void		print_export(void);
int			check_key_err(char	*str);
int			split_env(char *f, char **key, char **val);
void		unset(t_cmd *cmd);
void		export(t_cmd *cmd);
char		**env_to_arr(void);
char		*getenv_val(char *key);

#endif