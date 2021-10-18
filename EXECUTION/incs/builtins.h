/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:49:26 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/18 18:52:00 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILTINS_H
# define BUILTINS_H

# include "execution.h" 


void		pwd(void);
void		cd(t_cmd *cmd);
void		echo(t_cmd	*cmd);


# endif