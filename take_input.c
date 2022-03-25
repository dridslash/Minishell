#include "minishell.h"

void	take_input(char **input)
{
	char	*tmp;

	*input = readline("$> ");
	if (*input == NULL)
		exit(0);
	while (pipe_in_end(*input))
	{
		tmp = readline("> ");
		*input = t_strjoin(*input, tmp);
		if (*input == NULL)
			exit(0);
		if (tmp)
			free(tmp);
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

char	*t_strjoin(char *s1, char *s2)
{
	char	*ret_string;
	int		i1;
	int		i2;

	if (s1 == NULL)
		return (ft_strdup(s2));
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
	return (ret_string);
}

char *char_join(char *string, char c)
{
	char	*return_string;
	int 	i;

	if (string == NULL)
		return (ft_strdup(&c));
	i = 0;
	return_string = malloc(sizeof(char) * ft_strlen(string) + 2);
	while (string[i] != '\0')
	{
		return_string[i] = string[i];
		i++;
	}
	return_string[i] = c;
	return_string[i + 1] = '\0';
	free (string);
	return (return_string);
}
