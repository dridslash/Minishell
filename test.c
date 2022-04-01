#include "minishell.h"

int main(int main, char **argv, char **env)
{
	t_env	*test;
	char	*input;
	char	**input_split;

	test = ft_env(env);
	while (1)
	{
		take_input(&input);
		if (check_errors(input))
		{
			input_split = split_input(input);
			check_env(input, input_split, test);
			free_all(input_split, input);
			system("leaks a.out");
			//check_dollar(input, &i1, &input_split[0], test);
			//check_dollar(input, &i1, &input_split[1], test);
			//check_dollar(input, &i1, &input_split[2], test);
		}
	}
}
