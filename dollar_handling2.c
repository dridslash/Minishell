#include "minishell.h"

void	get_single_q_dollar(char *input, int *i1, char **string)
{
	(*i1)++;
	while (input[*i1] != '\'')
	{
		*string = char_join(*string, input[*i1]);
		(*i1)++;
	}
}
