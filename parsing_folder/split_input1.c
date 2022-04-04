/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:11:25 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/04 19:58:24 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_words(char *string)
{
	int	i;
	int	ret_value;

	i = 0;
	ret_value = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
			skip_spaces(string, &i);
		else if (string[i] == '|')
			ret_value++;
		else if (string[i] == '>' || string[i] == '<')
			skip_redirections(string, &i, &ret_value);
		else if (string[i] != 34 && string[i] != 39)
			skip_words(string, &i, &ret_value);
		else
			skip_quotes(string, &i, &ret_value);
		i++;
	}
	return (ret_value);
}

char	**split_input(char *input)
{
	char	**ret;
	int		*size_of_words;

	ret = malloc(sizeof(char *) * (count_words(input) + 1));
	size_of_words = len_words(count_words(input), input);
	ret = alloc_words(size_of_words, count_words(input), ret);
	ret = fill_me(ret, input);
	free(size_of_words);
	return (ret);
}

void	skip_spaces(char *string, int *i)
{
	while (string[*i] == ' ')
		(*i)++;
	(*i)--;
}

void	skip_redirections(char *string, int *i, int *word_count)
{
	(*i)++;
	if (string[*i] == '>' || string[*i] == '<')
		(*i)++;
	(*i)--;
	*word_count += 1;
}

void	skip_words(char *string, int *i, int *word_count)
{
	while (string[*i] != '\0' && string[*i] != '<'
		&& string[*i] != '>' && string[*i] != '|'
		&& string[*i] != ' ' && string[*i] != 34
		&& string[*i] != 39)
		(*i)++;
	if (string[*i] == 34 || string[*i] == 39)
	{
		skip_quotes(string, i, word_count);
		return ;
	}
	*word_count += 1;
	(*i)--;
}
