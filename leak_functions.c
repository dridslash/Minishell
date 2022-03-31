#include "minishell.h"

void	free_all(char **p, char *p2)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
	free(p2);
}

void	free_split_in(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}
