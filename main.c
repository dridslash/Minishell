#include "minishell.h"

int	main(int argc, char *argv[])
{
	char	*input;
	char	**input_split;

	input = NULL;
	while (1)
	{
		take_input(&input);
		if (check_errors(input))
			input_split = split_input(input);
	}
}
