#include "minishell.h"

int	another_quote(char *string, int *i1, char *split_string, int *i)
{
	while (string[*i1] != '\0')
	{
		if (string[*i1] == 34 || string[*i1] == 39)
			return (2);
		if (string[*i1] == ' ' || string[*i1] == '|'
			|| string[*i] == '<' || string[*i] == '>')
		{
			split_string[*i] = '\0';
			return (1);
		}
		split_string[*i] = string[*i1];
		(*i)++;
		(*i1)++;
	}
	if (string[*i1] == '\0')
		split_string[*i] = '\0';
	return (1);
}
