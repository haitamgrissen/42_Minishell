/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:36:37 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/03 11:29:37 by hgrissen         ###   ########.fr       */
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


int		is_builtin(char *str)
{
	if (!ft_strcmp(str, "echo"))
		return (1);
	if (!ft_strcmp(str, "cd"))
		return (1);
	if (!ft_strcmp(str, "pwd"))
		return (1);
	if (!ft_strcmp(str, "env"))
		return (1);
	if (!ft_strcmp(str, "export"))
		return (1);
	if (!ft_strcmp(str, "unset"))
		return (1);
	if (!ft_strcmp(str, "exit"))
		return (1);
	return (0);
}

void	execute_builtin(t_cmd *cmd)
{
	cmd->args = cmd->args + 1;
	if (!ft_strcmp(cmd->cmd, ECHO))
		echo(cmd);
	else if (!ft_strcmp(cmd->cmd, CD))
		cd(cmd);
	else if (!ft_strcmp(cmd->cmd, PWD))
		pwd();
	else if (!ft_strcmp(cmd->cmd, ENV))
		print_env();
	else if (!ft_strcmp(cmd->cmd, EXPORT))
		export(cmd);
	else if (!ft_strcmp(cmd->cmd, UNSET))
		unset(cmd);
	else if (!ft_strcmp(cmd->cmd, EXIT))
		exit_builtin();
}

void	execute_cmd(t_cmd *cmd)
{
	if (is_builtin(cmd->cmd))
		execute_builtin(cmd);
	else
	{
		char *str = get_working_path(cmd->cmd);
		if (str)
			execve(str, cmd->args, g_exe.envs_arr);
		else
			printf("command not found\n");
	}
}


int     main(int ac, char **av, char **env)
{
	
	
	
	init_envs(env);




//
	t_cmd	*cmd;
	cmd = malloc(sizeof(t_cmd));
	cmd->cmd = "echo";
	cmd->next = NULL;//malloc(sizeof(t_cmd));
	// cmd->next->cmd = "cd";
	// cmd->next->next = malloc(sizeof(t_cmd));
	// cmd->next->next->cmd = "grep";
	// cmd->next->next->next = NULL;

	execute_pipe(cmd);

	return 0;

	
//char	*str = get_working_path(av[1]);
	// g_exe.envs_arr = env_to_arr();
	
	// cmd.args = av + 1;
	// cmd.args_count = ac - 2;
	// cmd.cmd = av[1];
	
	// execute_cmd(&cmd);
	
	//system("leaks a.out");
	
	//execve();
	//print_export();
	return 0;

	// char	*CMD[] = {"lsbdf", "-la", NULL};
	// int ret = execve("/bin/lsbbddsf", CMD, NULL);
	// printf("ret : %d", ret);



	
//echo tests
	// cmd.args = av + 1;
	// cmd.args_count = ac - 1;
	// echo(&cmd);
	// return (0);


//cd and pwd test
	// cmd.args = av + 1;
	// cmd.args_count = ac - 1;
	// t_envs	*pwdd;
	// t_envs  *oldpwd;

	// //remove_node(&envs, av[2]);
	// //remove_node(&envs, av[3]);
	// cd(&cmd);
	// pwd();
	// //print_env();
	// pwdd = getenv_node("PWD");
	// oldpwd = getenv_node("OLDPWD");
	// printf("old pwd: %s\ncurrent pwd :%s\n", oldpwd->val, pwdd->val);
	// printf("**********************\n");
	// char 	*buffer = malloc(1000);
	// perror(buffer);
	// system("leaks a.out");
	// return 0;
	//return 0;

//unset test and export
	// cmd.args = av + 1;
	// cmd.args_count = ac - 1;
	// char	**array;
	
	// array = env_to_arr();
	// int i = -1;
	// while (array[++i])
	// {
	// 	printf("%s\n", array[i]);
	// 	//free(array[i]);
	// }
	//free(array);
	
	//export(&cmd);
	
	//unset(&cmd);
	//add_node(envs, av[1]);
	//remove_node(&envs, av[2]);
	//remove_node(&envs, av[3]);
	//remove_node(&envs, av[4]);



////TEST SPLITE PATHs
	

	
	//system("leaks a.out");

/// EXECVE TEST

	// char *a[] = {"", "-la", NULL};
	// char *str = "/bin/ls";
	// execve(str, a, NULL);

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