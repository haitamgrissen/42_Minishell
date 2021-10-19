/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:49:26 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/19 14:31:39 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILTINS_H
# define BUILTINS_H

# include "execution.h" 


void		pwd(void);
void		cd(t_cmd *cmd);
void		echo(t_cmd	*cmd);



t_envs		*getenv_node(t_envs *head, char	*str);
/*
	enviroment and export and unset fuctions
	might be removed from here and added to another heaader file containing BUILTINS functions
*/ 
t_envs		*init_envs(char **env);
void		add_node(t_envs *head, char	*str);
void		remove_node(t_envs **head, char	*key);
void		print_env(t_envs	*envs);
void		print_export(t_envs *envs);


int			check_key_err(char	*str);
int			split_env(char *f, char **key, char **val);


void		unset(t_cmd *cmd);
void		export(t_cmd *cmd);
# endif