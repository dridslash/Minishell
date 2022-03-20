#include "minishell.h"

void	go_to_quote(char *string, int *i, char q)
{
	while (string[*i] != q)
		(*i)++;
	(*i)++;
}

int	find_end(char *string, int *i, char *q)
{
	while (string[*i] != '\0')
	{
		if (string[*i] == 34 || string[*i] == 39)
		{
			*q = string[*i];
			(*i)++;
			return (0);
		}
		if (string[*i] == ' ' || string[*i] == '|'
			|| string[*i] == '<' || string[*i] == '>')
			return (1);
		(*i)++;
	}
	return (1);
}
