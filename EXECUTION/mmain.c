# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/wait.h>

typedef struct cmd
{
	char *args[5];

}	cm;

int		main (int ac, char **av, char **env)
{
	cm  command[10];

	command[0].args[0] = strdup("/bin/cat");
	command[0].args[1] = strdup("/dev/random");
	command[0].args[2] = NULL;
	command[1].args[0] = strdup("/usr/bin/head");
	command[1].args[1] = strdup("-c 10");
	command[1].args[2] = NULL;
	command[2].args[0] = strdup("/bin/cat");
	command[2].args[1] = NULL;
	int pipe_[2];


	//pid_t f = fork();
	int pids[1000];
	int i = 0;
	int p_out = 1;
	int p_in = 0;
	while(i < 2)
	{
		pipe(pipe_);
		p_out = pipe_[1];
		pids[i] = fork();
		if (pids[i] == 0)
		{
			dup2(p_out,1);
			close(pipe_[1]);
			dup2(p_in, 0);
			close(pipe_[0]);
			execve(command[i].args[0],command[i].args, env);
		}
		if (p_in != 0)
			close(p_in);
		p_in = pipe_[0];
		close(p_out);
		i++;
	}
	close(p_out);
	pids[i] = fork();

	if (pids[i] == 0)
	{
		dup2(p_in,0);
		close(p_in);
		close(pipe_[1]);
		execve(command[2].args[0],command[2].args, env);
	}
	i = 0;
	while(i < 3)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}

}