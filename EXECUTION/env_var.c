/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:02:17 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/17 13:32:54 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	print_export(t_envs *envs)
{
	t_envs	*current;
	
	current = envs;
	while(current->next != NULL)
	{
		if (current->val == NULL)
			printf("declare -x %s\n", current->key);
		else
			printf("declare -x %s=\"%s\"\n", current->key, current->val);
		current = current->next;
	}
	if (current->val == NULL)
			printf("declare -x %s\n", current->key);
	else
			printf("declare -x %s=\"%s\"\n", current->key, current->val);
}

void	check_env_var(t_envs *envs, char	*str)
{
	t_envs	*current;
	
	current = envs;
	while(current->next != NULL)
	{
		if (ft_strcmp(envs->key, str) == 0)
			
		current = current->next;
	}
}

void	print_env(t_envs	*envs)
{
	t_envs	*current;
	
	current = envs;
	while(current->next != NULL)
	{
		if (current->val != NULL)
			printf("%s=%s\n", current->key, current->val);
		current = current->next;
	}
	if (current->val != NULL)
			printf("%s=%s\n", current->key, current->val);
}

void	split_env(char *f, char **key, char **val)
{
	int		i;
	int		j;

	i = 0;
	if (!f)
		return ;
	while (f[i] != '=' && f[i])
		i++;

	(*key) = ft_substr(f, 0, i);
	j = 0;
	while (f[i + j])
		j++;
	if (f[i] != '=')
		(*val) = NULL;
	else
		(*val) = ft_substr(f, i + 1, j);
}

void	add_node(t_envs *head, char	*str)
{
	t_envs	*current;
	t_envs	*new;

	current = head;
	while (current->next != NULL)
		current = current->next;
	new = (t_envs *)malloc(sizeof(t_envs));
	current->next = new;
	split_env(ft_strdup(str), &new->key, &new->val);
	new->next = NULL;
	new->prev = current;
}

t_envs	*init_envs(char **env)
{
	t_envs	*ret;
	int		i;

	ret = (t_envs *)malloc(sizeof(t_envs));
	split_env(ft_strdup(env[0]), &ret->key, &ret->val);
	ret->next = NULL;
	ret->prev = NULL;
	i = 1;
	while (env[i])
	{
		add_node(ret, env[i]);
		i++;
	}
	return (ret);
}
