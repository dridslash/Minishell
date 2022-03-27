#include "minishell.h"

void	join_mark(char **ret_string, char *split_string, int *i)
{
	(*i)++;
	*ret_string = char_join(*ret_string, '$');
	*ret_string = char_join(*ret_string, '?');
	while (split_string[*i])
	{
		*ret_string = char_join(*ret_string, split_string[*i]);
		(*i)++;
	}
	(*i)--;
}
