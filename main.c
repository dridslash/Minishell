#include "minishell.h"

int	main(void)
{
	char	*input;
	char	**input_split;

	while (1)
	{
		input = readline("$> ");
		if (check_errors(input))
			input_split = split_input(input);
	}
}
