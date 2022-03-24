#include "minishell.h"
//EXEC
#include "exec_test.h"
//EXEC

int	main(int argc, char *argv[], char **env)
{
	char	*input;
	char	**input_split;
	t_env	*env_var;

	env_var = ft_env(env);
	while (1)
	{
		take_input(&input);
		if (check_errors(input))
		{
			input_split = split_input(input);
			//check_env(input, split_input, env_var);
		}
	}
}
