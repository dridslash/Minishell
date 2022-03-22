#include "minishell.h"

void	take_input(char **input)
{
	char	*tmp;

	*input = readline("$> ");
	while (pipe_in_end(*input))
	{
		tmp = readline("> ");
		*input = ft_strjoin(*input, tmp);
	}
}

int	pipe_in_end(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '|')
		{
			i++;
			while (input[i] == ' ')
				i++;
			if (input[i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	len(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*ret_string;
	int		i1;
	int		i2;

	ret_string = malloc(sizeof(char) * (len(s1) + len(s2) + 1));
	i1 = 0;
	i2 = 0;
	while (s1[i1] != '\0')
	{
		ret_string[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\0')
	{
		ret_string[i1] = s2[i2];
		i1++;
		i2++;
	}
	ret_string[i1] = '\0';
	free(s1);
	free(s2);
	return (ret_string);
}
