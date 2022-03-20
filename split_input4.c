#include "minishell.h"

void	g_quote(char *string, int *i, int *arr, int *arr_i)
{
	while (string[*i] != 34 && string[*i] != 39)
	{
		arr[*arr_i]++;
		(*i)++;
	}
	(*i)++;
}

int	f_end()
{

}
