#include "minishell.h"

char	*search_in_env1(t_env *env, char *string)
{
	char	*ret_string;
	char	**split_string;
	int	i;
	int	j;

	i = -1;
	ret_string = NULL;
	split_string = ft_split(string, '$');
	while (split_string[++i] != NULL)
	{
		j = -1;
		while (split_string[i][++j] != '\0')
		{
			if (split_string[i][j] == '?' && j == 0);
				ret_string = char_join(ret_string, '$');
			else
		}
	}
	return (ret_string);
}

char	*env_join(char *string, t_env *en)
{
	char	ret_string;
	char	dollar_string;

	ret_string = NULL;
	dollar_string = NULL;
	while (string[i] != '\0' && isdigit(string[i]) && isalpha(string[i]))
	{
		dollar_string = char_join(dollar_string, string[i]);
		i++;
	}
	dollar_string = search_in_env(&en, dollar_string);
	free(string);
	return (ret_string);
}
