/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:36:37 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/18 15:23:03 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incs/execution.h"
#include "./incs/builtins.h"


void	printbyindex(t_envs *head, int index)
{
	t_envs	*current;
	int		i;

	current = head;
	i = 0;
	while (current->next != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	if (i < index)
		printf("this is the last node\n");
	if (current->val != NULL)
		printf("%s=%s\n", current->key, current->val);
	if (current->val == NULL)
		printf("NULL\n");
}

void	free_envs(t_envs	**head)
{
	t_envs	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->prev->key != NULL)
			free(tmp->prev->key);
		if (tmp->prev->val != NULL)
			free(tmp->prev->val);
		if (tmp->prev != NULL)
			free(tmp->prev);
	}

	if (tmp->key != NULL)
		free(tmp->key);
	if (tmp->val != NULL)
		free(tmp->val);
	if (tmp != NULL)
		free(tmp);
	

}


int     main(int ac, char **av, char **env)
{
	t_cmd	cmd;

	cmd.args = av + 1;
	cmd.args_count = ac - 1;
	
	cd(&cmd);
	pwd();
	system("leaks a.out");
	return 0;
	t_envs	*envs;

	envs = init_envs(env);
	add_node(envs, av[1]);
	unset(&envs, av[2]);
	//unset(&envs, av[3]);
	//unset(&envs, av[4]);

	//printbyindex(envs, 50);
	print_env(envs);
	//print_export(envs);  
	//check_env_var(envs, av[1]);

	
	//free_envs(&envs);
	//system("leaks a.out");
}