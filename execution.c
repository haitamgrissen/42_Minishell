/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:36:37 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/15 21:42:04 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




void	execute_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		exit(0);
	if (is_builtin(cmd->cmd))
		execute_builtin(cmd);
	else
	{
		char *str = get_working_path(cmd->cmd);
		if (str)
			execve(str, cmd->args, g_exe.envs_arr);
		else
		{
			write(2, cmd->cmd, ft_strlen(cmd->cmd));
			write(2, ": ", 2);
			write(2, "command not found\n", 18);
		}
	}
	exit(0);
}


// int     main(int ac, char **av, char **env)
// {
// 	init_envs(env);

// 	t_cmd	*cmd;
// 	cmd = malloc(sizeof(t_cmd));
// 	cmd->cmd = ft_strdup("cat");
// 	cmd->args = ft_split("cat", ' ');

// 	cmd->rdr = NULL;
// 	// cmd->rdr = malloc(sizeof(t_redirection));
// 	// cmd->rdr->type = RDROUT;
// 	// cmd->rdr->file = ft_strdup("hello");

// 	// cmd->rdr->next = malloc(sizeof(t_redirection));
// 	// cmd->rdr->next->type = APPEND;
// 	// cmd->rdr->next->file = ft_strdup("Nor");

// 	// cmd->rdr->next->next = malloc(sizeof(t_redirection));
// 	// cmd->rdr->next->next->type = HEREDOC;
// 	// cmd->rdr->next->next->file = ft_strdup("Nor1");

// 	// cmd->rdr->next->next->next = malloc(sizeof(t_redirection));
// 	// cmd->rdr->next->next->next->type = HEREDOC;
// 	// cmd->rdr->next->next->next->file = ft_strdup("Nizar");
// 	// cmd->rdr->next->next->next->next = NULL;

// 	// cmd->next = NULL;
	
// 	// //g_exe.envs_arr = env_to_arr();
// 	// //cmd->args_count = 1;
// 	// //unset(cmd);
// 	// execute_pipe(cmd);
// 	// while(1)
// 	// ;
// 	// //system("leaks hada");
// 	// //print_export();
// 	// //system("leaks a.out");
// 	// //execute_pipe(cmd);
// 	// return 0;


	
// 	cmd->next = malloc(sizeof(t_cmd));
// 	cmd->next->cmd = ft_strdup("head");
// 	cmd->next->args = ft_split("head -c 20", ' ');
// 	cmd->next->rdr = NULL;
// 	// cmd->next->rdr = malloc(sizeof(t_redirection));
// 	// cmd->next->rdr->type = RDRIN;
// 	// cmd->next->rdr->file = ft_strdup("hello");

// 	// cmd->next->rdr->next = malloc(sizeof(t_redirection));
// 	// cmd->next->rdr->next->type = RDROUT;
// 	// cmd->next->rdr->next->file = ft_strdup("Norr");

// 	// cmd->next->rdr->next->next = malloc(sizeof(t_redirection));
// 	// cmd->next->rdr->next->next->type = HEREDOC;
// 	// cmd->next->rdr->next->next->file = ft_strdup("Nor2");

// 	// cmd->next->rdr->next->next->next = malloc(sizeof(t_redirection));
// 	// cmd->next->rdr->next->next->next->type = HEREDOC;
// 	// cmd->next->rdr->next->next->next->file = ft_strdup("Nizar1");
// 	// cmd->next->rdr->next->next->next->next = NULL;
	
// 	cmd->next->next = malloc(sizeof(t_cmd));
// 	cmd->next->next->cmd = ft_strdup("cat");
// 	cmd->next->next->args = ft_split("cat", ' ');
// 	cmd->next->next->next = NULL;
// 	cmd->next->next->rdr = NULL;


// 	execute_pipe(cmd);

// 	//system("leaks hada");
// 	//while (1);
// //char	*str = get_working_path(av[1]);
// 	// g_exe.envs_arr = env_to_arr();
	
// 	// cmd.args = av + 1;
// 	// cmd.args_count = ac - 2;
// 	// cmd.cmd = av[1];
	
// 	// execute_cmd(&cmd);
	
// 	//system("leaks a.out");
	
// 	//execve();
// 	//print_export();
// 	return 0;

// 	// char	*CMD[] = {"lsbdf", "-la", NULL};
// 	// int ret = execve("/bin/lsbbddsf", CMD, NULL);
// 	// printf("ret : %d", ret);



	
// //echo tests
// 	// cmd.args = av + 1;
// 	// cmd.args_count = ac - 1;
// 	// echo(&cmd);
// 	// return (0);


// //cd and pwd test
// 	// cmd.args = av + 1;
// 	// cmd.args_count = ac - 1;
// 	// t_envs	*pwdd;
// 	// t_envs  *oldpwd;

// 	// //remove_node(&envs, av[2]);
// 	// //remove_node(&envs, av[3]);
// 	// cd(&cmd);
// 	// pwd();
// 	// //print_env();
// 	// pwdd = getenv_node("PWD");
// 	// oldpwd = getenv_node("OLDPWD");
// 	// printf("old pwd: %s\ncurrent pwd :%s\n", oldpwd->val, pwdd->val);
// 	// printf("**********************\n");
// 	// char 	*buffer = malloc(1000);
// 	// perror(buffer);
// 	// system("leaks a.out");
// 	// return 0;
// 	//return 0;

// //unset test and export
// 	// cmd.args = av + 1;
// 	// cmd.args_count = ac - 1;
// 	// char	**array;
	
// 	// array = env_to_arr();
// 	// int i = -1;
// 	// while (array[++i])
// 	// {
// 	// 	printf("%s\n", array[i]);
// 	// 	//free(array[i]);
// 	// }
// 	//free(array);
	
// 	//export(&cmd);
	
// 	//unset(&cmd);
// 	//add_node(envs, av[1]);
// 	//remove_node(&envs, av[2]);
// 	//remove_node(&envs, av[3]);
// 	//remove_node(&envs, av[4]);



// ////TEST SPLITE PATHs
	

	
// 	//system("leaks a.out");

// /// EXECVE TEST

// 	// char *a[] = {"", "-la", NULL};
// 	// char *str = "/bin/ls";
// 	// execve(str, a, NULL);

// 	//printf("finished exe\n");
// 	//return 0;

// 	//printbyindex(envs, 1);
// 	//print_env();
// 	//print_export(); 
// 	//free(cmd.args[0]);
// 	//system("leaks a.out");
// 	//getenv_node(envs, av[1]);

	
// 	//free_envs(&envs);
// }