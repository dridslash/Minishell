#include "minishell.h"

void	pipe_size(int *arr, int *arr_i)
{
	arr[*arr_i] += 1;
	(*arr_i)++;
}

void	redirection_size(char *string, int *i, int *arr, int *arr_i)
{
	arr[*arr_i] += 1;
	(*i)++;
	if (string[*i] == '<' || string[*i] == '>')
	{
		arr[*arr_i] += 1;
		(*i)++;
	}
	(*arr_i)++;
	(*i)--;
}

void	word_size(char *string, int *i, int *arr, int *arr_i)
{
	while (string[*i] != '\0' && string[*i] != '<'
		&& string[*i] != '>' && string[*i] != '|'
		&& string[*i] != ' ')
	{
		arr[*arr_i]++;
		(*i)++;
	}
	(*i)--;
	*arr_i += 1;
}

void	quotes_size(char *string, int *i, int *arr, int *arr_i)
{
	/*char q;

	q = 39;
	if (string[*i] == 34)
		q = 34;
	(*i)++;
	while (string[*i] != '\0')
	{
		if ((string[*i] == q && (string[*i + 1] == ' '
			|| string[*i + 1] == '\0')) || string[*i] == '\0')
		{
			*arr_i += 1;
			return ;
		}
		if (string[*i] != q)
			arr[*arr_i]++;
		(*i)++;
	}*/
	char	val;

	val = 39;
	if (string[*i] == 34)
		val = 34;
	(*i)++;
	while (1)
	{
		g_quote(string, i, arr, arr_i);
		if (string[*i] == '\0' || string[*i] == ' '
			|| string[*i] == '|' || string[*i] == '<'
			|| string[*i] == '>')
		{
			*arr_i += 1;
			break;
		}
		if (find_end(string, i, &val))
		{
			*arr_i += 1;
			break;
		}
	}
	(*i)--;
}

char **alloc_words(int *arr, int words, char **ret)
{
	int	i;
	int	arr_ind;

	arr_ind = 0;
	i = 0;
	while (i < words)
	{
		ret[i] = malloc(sizeof(char) * arr[arr_ind] + 1);
		i++;
		arr_ind++;
	}
	ret[i] = NULL;
	return (ret);
}
