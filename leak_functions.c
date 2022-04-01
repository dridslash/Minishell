#include "minishell.h"

void	free_all(char **p, char *p2, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (p[i])
			free(p[i]);
	}
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

void	free_double_p(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}
