/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:03:41 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/14 18:52:46 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_parser.h"

void cntl_c(int sig)
{
	g_exe.exite_err = 130;
	write(1,"\n",1);
	if (g_exe.exite_err != 0)
		printf("twerkat");
	printf("BASH$>: ");
}
void cntl_slash(int sig)
{
	char *str;
	str = NULL; 
	str = ft_itoa(sig);
	printf("slash twerkat :");
	printf("%s",str);
	printf("\n");
	g_exe.exite_err = 131;
	free(str);
}
void catch_the_signal()
{
	signal(SIGINT,cntl_c);
	signal(SIGQUIT,cntl_slash);
}