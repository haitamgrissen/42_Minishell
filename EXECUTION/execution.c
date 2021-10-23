/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:36:37 by hgrissen          #+#    #+#             */
/*   Updated: 2021/10/22 21:05:28 by hgrissen         ###   ########.fr       */
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

void	execute_cmd(t_cmd *cmd)
{
	
}




int     main(int ac, char **av, char **env)
{
	t_cmd	cmd;
	t_envs	*envs;
	
	
	init_envs(env);

	// char	*CMD[] = {"lsbdf", "-la", NULL};
	// int ret = execve("/bin/lsbbddsf", CMD, NULL);
	// printf("ret : %d", ret);



	
//echo tests
	// cmd.args = av + 1;
	// cmd.args_count = ac - 1;
	// echo(&cmd);
	//return (0);


//cd and pwd test
	// cmd.args = av + 1;
	// cmd.args_count = ac - 1;
	// //remove_node(&envs, av[2]);
	// //remove_node(&envs, av[3]);
	// cd(&cmd);
	// pwd();
	// print_env(envs);
	// printf("**********************\n");
	// char 	*buffer = malloc(1000);
	// perror(buffer);
	// // system("leaks a.out");
	// // return 0;
	// return 0;

//unset test and export
	cmd.args = av + 1;
	cmd.args_count = ac - 1;
	char	**array;
	
	array = env_to_arr();
	int i = -1;
	while (array[++i])
	{
		printf("%s\n", array[i]);
		//free(array[i]);
	}
	//free(array);
	
	//export(&cmd);
	
	//unset(&cmd);
	//add_node(envs, av[1]);
	//remove_node(&envs, av[2]);
	//remove_node(&envs, av[3]);
	//remove_node(&envs, av[4]);


/// EXECVE TEST

	//char *a[] = {"/bin/ls", "-la", (char *)0};

	//execve(a[0], a, NULL);

	//printf("finished exe\n");
	//return 0;

	//printbyindex(envs, 1);
	//print_env();
	//print_export(); 
	//free(cmd.args[0]);
	//system("leaks a.out");
	//getenv_node(envs, av[1]);

	
	//free_envs(&envs);
}