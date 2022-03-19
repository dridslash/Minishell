#include "minishell.h"

void	check_double_quotes(char *input, int *i)
{
	(*i)++;
	while (input[*i] != '\0')
	{
		if (input[*i] == 34)
			return ;
		(*i)++;
	}
	printf("Non closed double quotes !\n");
	exit(EXIT_FAILURE);
}

void	check_single_quotes(char *input, int *i)
{
	(*i)++;
	while (input[*i] != '\0')
	{
		if (input[*i] == 39)
			return ;
		(*i)++;
	}
	printf("Non closed single quotes !\n");
	exit(EXIT_FAILURE);
}
