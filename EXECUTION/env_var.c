/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:02:17 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/18 13:12:04 by hgrissen         ###   ########.fr       */
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

t_envs	*check_env_var(t_envs *head, char	*str)
{
	t_envs	*current;
	
	current = head;
	while(current->next != NULL)
	{
		if (ft_strcmp(current->key, str) == 0)
			return(current);
		current = current->next;
	}
	if (ft_strcmp(current->key, str) == 0)
			return(current);
	return(NULL);
}


int		split_env(char *f, char **key, char **val)
{
	int		i;
	int		j;

	i = 0;
	if (!f || !ft_isalpha(f[0]))
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
	return 0;
}

void	unset(t_envs **head, char	*key)
{
	t_envs	*tmp;

	if ((tmp = check_env_var(*head, key)) != NULL)
	{
		if (tmp->prev == NULL)
		{
			tmp->next->prev = NULL;
			*head = tmp->next;////////
		}
		else if (tmp->next == NULL)
		{
			tmp->prev->next = NULL;
		}
		else
		{
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
		}

		//free the shit out of here
		free(tmp->key);
		if (tmp->val != NULL)
			free(tmp->val);
		free(tmp);
	}
}

int		update_node(t_envs *head, char	*str)
{
	t_envs	*tmp;
	char	*tmp_key;
	int		i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	tmp_key = ft_substr(str, 0, i);
	if ((tmp = check_env_var(head, tmp_key)) != NULL)
	{
		if (tmp->val != NULL)
			free(tmp->val);
		split_env(ft_strdup(str), &tmp->key, &tmp->val);
		free(tmp_key);
		return (1);
	}
	free(tmp_key);
	return (0);
}



int		check_key_err(char	*str)
{
	int	i;
	if (!ft_isalpha(str[0]))
		return (0);
	i = 0;
	while (str[i] != '=' && str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return 1;
}
void	add_node(t_envs *head, char	*str)
{
	t_envs	*current;
	t_envs	*new;

	if (!check_key_err(str))
		return;
	current = head;
	if (update_node(head, str) == 1)
		return;
	while (current->next != NULL)
		current = current->next;
	new = (t_envs *)malloc(sizeof(t_envs));
	current->next = new;
	new->key = NULL;
	new->val = NULL;
	split_env(ft_strdup(str), &new->key, &new->val);
	new->next = NULL;
	new->prev = current;
}

t_envs	*init_envs(char **env)
{
	t_envs	*ret;
	int		i;

	ret = (t_envs *)malloc(sizeof(t_envs));
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
	return (ret);
}
