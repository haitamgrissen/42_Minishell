/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:57:01 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/26 20:08:23 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipeline **parse_info(char *line)
{
    char *ch_line;
    t_pipeline **parse;
    int i;
    int flag;
    
    ch_line = ft_strdup("");
    while(line[i]!= '\0')
    {
        if (line[i] == '\'')
        {
            while(line[i] != )
        }
    }    
}