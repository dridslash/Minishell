#include "minishell.h"
//EXEC
#include "exec_test.h"
//EXEC

void	check_env(char *input, char **split_input, t_env *env)
{
	int	i1;
	int	i2;

	i2 = 0;
	i1 = 0;
	while (input[i1] != '\0')
	{
		if (input[i1] == ' ')
			skip_spaces(input, &i1);
		else if (input[i1] == '|')
			i2++;
		else if (input[i1] == '<' || input[i1] == '>')
			skip_red2(input, &i1, &i2);
		else
			check_dollar(input, &i1, split_input, &i2);
		i1++;
	}
}

void	skip_red2(char *input, int *i1, int *i2)
{
	(*i1)++;
	if (input[*i1] == '<' || input[*i1] == '>')
		(*i1)++;
	(*i2)++;
	(*i1)--;
}

void	check_dollar(char *input, int *i1, char **split_input, int *i2)
{
	char	*string;
	char	*tmp;

	while (input[*i1] != '\0')
	{
		
		*i1 += 1;
	}
}
