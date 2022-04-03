/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:27:22 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/03 13:52:29 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	skip_quotes(char *string, int *i, int *word_count)
{
	char	val;

	val = 39;
	if (string[*i] == 34)
		val = 34;
	(*i)++;
	*word_count += 1;
	while (1)
	{
		go_to_quote(string, i, val);
		if (string[*i] == '\0' || string[*i] == ' '
			|| string[*i] == '|' || string[*i] == '<'
			|| string[*i] == '>')
			break ;
		if (find_end(string, i, &val))
			break ;
	}
	(*i)--;
}	

int	find_quote(char *string, int i)
{
	while (string[i] != '\0')
	{
		if (string[i] == '|' || string[i] == '>'
			|| string[i] == '<')
			return (0);
		if (string[i] == 34 || string[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

int	*len_words(int size, char *string)
{
	int	*ret_array;
	int	i;
	int	arr_index;

	i = 0;
	arr_index = 0;
	ret_array = ft_calloc(size);
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
			skip_spaces(string, &i);
		else if (string[i] == '|')
			pipe_size(ret_array, &arr_index);
		else if (string[i] == '>' || string[i] == '<')
			redirection_size(string, &i, ret_array, &arr_index);
		else if (string[i] != 34 && string[i] != 39)
			word_size(string, &i, ret_array, &arr_index);
		else
			quotes_size(string, &i, ret_array, &arr_index);
		i++;
	}
	return (ret_array);
}

int	*ft_calloc(int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

void	inc_dec(int *i1, int *i2)
{
	(*i1)--;
	(*i2)++;
}
