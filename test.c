/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:56:42 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/09 15:59:19 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main ()
{
    char *str; 
    char *ptr;
    str = "hello; oui ; ls ;";
    ptr = malloc(sizeof(str));

    ptr = ft_substr(str,0,6);
    printf("%s\n",ptr);
    return (0);
    
}