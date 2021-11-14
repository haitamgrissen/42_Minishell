# include "new_parser.h"

int		is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int     main(int ac, char **av, char **env)
{
	t_lexer		*lexer;

	init_envs(env);
	catch_the_signal();
    while(TRUE)
    {
        g_exe.line = readline("BASH$>: ");
		if (!g_exe.line)
		{
			ft_putstr_fd("exit", 1);
			return (0);
		}
        if (g_exe.line[0] =='\0')
			continue ;

        add_history(g_exe.line);


		lexer = init_lexer(g_exe.line);
		parse(lexer);
		free(lexer);


		//system("leaks hada");
		free(g_exe.line);
		g_exe.line = NULL;
    }
    return(0);
}
