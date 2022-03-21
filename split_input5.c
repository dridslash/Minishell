#include "minishell.h"

char **fill_me(char **split_input, char *string)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	while (string[i1] != '\0')
	{
		printf("Char is : %c\n", string[i1]);
		if (string[i1] == ' ')
			skip_spaces(string, &i1);
		else if (string[i1] == '|')
			add_pipe(split_input[i2]);
		else if (string[i1] == '<' || string[i1] == '>')
			add_redi(string, &i1, split_input[i2]);
		else if (string[i1] != 34 && string[i1] != 39)
			add_word(string, &i1, split_input[i2]);
		else
			add_in_quote(string, &i1, split_input[i2]);
		i2++;
		i1++;
	}
	return (split_input);
}

void	add_pipe(char *split_input)
{
	split_input[0] = '|';
	split_input[1] = '\0';
}

void	add_redi(char *string, int *i1, char *split_input)
{
	int	n;

	n = 0;
	split_input[n] = string[*i1];
	n++;
	(*i1)++;
	if (string[*i1] == '<' || string[*i1] == '>')
	{
		split_input[n] = string[*i1];
		(*i1)++;
		n++;
	}
	(*i1)--;
	split_input[n] = '\0';
}

void	add_in_quote(char *string, int *i1, char *split_input)
{
	int	i;

	i = 0;
	while (1)
	{
		to_quote(string, i1, split_input, &i);
		if (string[*i1] == '\0' || string[*i1] == ' '
			|| string[*i1] == '|' || string[*i1] == '<'
			|| string[*i1] == '>')
		{
			split_input[i] = '\0';
			break;
		}
		if (another_quote(string, i1, split_input, &i) == 1)
			break;
	}
	(*i1)--;
}

void	to_quote(char *string, int *i1, char *split_input, int *i)
{
	char q;

	q = string[*i1];
	(*i1)++;
	while (string[*i1] != q)
	{
		split_input[*i] = string[*i1];
		(*i)++;
		(*i1)++;
	}
	(*i1)++;
}
