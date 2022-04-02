/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:27:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/02 12:27:55 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
		&& string[*i] != ' ' && string[*i] != 39
		&& string[*i] != 34)
	{
		arr[*arr_i]++;
		(*i)++;
	}
	if (string[*i] == 34 || string[*i] == 39)
	{
		quotes_size(string, i, arr, arr_i);
		return ;
	}
	(*i)--;
	*arr_i += 1;
}

void	quotes_size(char *string, int *i, int *arr, int *arr_i)
{
	char	val;

	val = 39;
	if (string[*i] == 34)
		val = 34;
	(*i)++;
	while (1)
	{
		g_quote(string, i, &arr[*arr_i], val);
		if (string[*i] == '\0' || string[*i] == ' '
			|| string[*i] == '|' || string[*i] == '<'
			|| string[*i] == '>')
		{
			*arr_i += 1;
			break ;
		}
		if (f_end(string, i, arr, arr_i) == 1)
			break ;
		else if (f_end(string, i, arr, arr_i) == 2)
		{
			val = string[*i];
			(*i)++;
		}
	}
	(*i)--;
}

char	**alloc_words(int *arr, int words, char **ret)
{
	int	i;

	i = 0;
	while (i < words)
	{
		ret[i] = malloc(sizeof(char) * arr[i] + 1);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
