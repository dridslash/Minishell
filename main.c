#include "minishell.h"
//EXEC
#include "exec_test.h"
//EXEC

int	main(int argc, char *argv[], char **env)
{
	char	*input;
	char	**input_split;
	t_env	*env_var;
	//Struct

	env_var = ft_env(env);
	/*while (1)
	{
		take_input(&input);
		//Signal
		if (check_errors(input))
		{
			input_split = split_input(input);
			check_env(input, input_split, env_var);
			int j = -1;
			while (++j < count_words(input))
				printf("--->%s<---\n", input_split[j]);
			//function to parse everything into struct
			//execute
		}
	}*/
	system("leaks a.out");
}
