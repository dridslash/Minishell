/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:11:25 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/20 12:30:29 by oessayeg         ###   ########.fr       */
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
	printf("Words : %d\n", ret_value);
	return (ret_value);
}

char	**split_input(char *input)
{
	char	**ret_value;
	//int		*size_of_words;

	ret_value = malloc(sizeof(char *) * count_words(input) + 1);
	return (ret_value);
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
		&& string[*i] != ' ')
		(*i)++;
	(*i)--;
	*word_count += 1;
}
