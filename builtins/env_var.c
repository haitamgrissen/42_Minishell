/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:02:17 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 23:16:02 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env(void)
{
	t_envs	*current;

	current = g_exe.envs_list;
	while (current->next != NULL)
	{
		if (current->val != NULL)
			printf("%s=%s\n", current->key, current->val);
		current = current->next;
	}
	if (current->val != NULL)
		printf("%s=%s\n", current->key, current->val);
}

t_envs	*getenv_node(char	*key)
{
	t_envs	*current;

	if (!key)
		return (NULL);
	current = g_exe.envs_list;
	while (current->next != NULL)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	if (ft_strcmp(current->key, key) == 0)
		return (current);
	return (NULL);
}

int	split_env(char *f, char **key, char **val)
{
	int		i;
	int		j;

	i = 0;
	if (!f || (!ft_isalpha(f[0]) && f[0] != '_'))
	{
		free(f);
		return (1);
	}
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
	free(f);
	return (0);
}

int	check_key_err(char	*str)
{
	int	i;

	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 0;
	while (str[i] != '=' && str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	init_envs(char **env)
{
	t_envs	*ret;
	int		i;

	ret = (t_envs *)malloc(sizeof(t_envs));
	g_exe.envs_list = ret;
	ret->key = NULL;
	ret->val = NULL;
	split_env(ft_strdup(env[0]), &ret->key, &ret->val);
	ret->next = NULL;
	ret->prev = NULL;
	i = 1;
	while (env[i])
	{
		add_node(ret, env[i]);
		i++;
	}
	g_exe.envs_arr = env_to_arr();
}
