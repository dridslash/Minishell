#include "minishell.h"

char	*without_nl(char *s)
{
	char	*ret_string;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	ret_string = malloc(sizeof(char) * i);
	i = -1;
	while (s[++i] != '\n' && s[i] != '\0')
		ret_string[i] = s[i];
	ret_string[i] = '\0';
	return (ret_string);
}
