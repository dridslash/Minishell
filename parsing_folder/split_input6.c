/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:27:44 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/02 12:58:00 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	another_quote(char *string, int *i1, char *split_string, int *i)
{
	while (string[*i1] != '\0')
	{
		if (string[*i1] == 34 || string[*i1] == 39)
			return (2);
		if (string[*i1] == ' ' || string[*i1] == '|'
			|| string[*i1] == '<' || string[*i1] == '>')
		{
			split_string[*i] = '\0';
			return (1);
		}
		split_string[*i] = string[*i1];
		(*i)++;
		(*i1)++;
	}
	if (string[*i1] == '\0')
		split_string[*i] = '\0';
	return (1);
}

void	go_to_quote2(char *string, int *i1, char *split_input, int *i)
{
	char	q;

	q = string[*i1];
	*i1 += 1;
	while (string[*i1] != q)
	{
		split_input[*i] = string[*i1];
		(*i1)++;
		(*i)++;
	}
	(*i1)++;
}

int	in(char *string, int *i1, char *split_input, int *i)
{
	if (string[*i1] == '\0' || string[*i1] == ' '
		|| string[*i1] == '|' || string[*i1] == '<'
		|| string[*i1] == '>')
	{
		split_input[*i] = '\0';
		return (1);
	}
	return (0);
}

int	another_q(char *string, int *i1, char *input_string, int *i)
{
	while (string[*i1] != '\0')
	{
		if (string[*i1] == 34 || string[*i1] == 39)
			return (0);
		if (string[*i1] == ' ' || string[*i1] == '|'
			|| string[*i1] == '<' || string[*i1] == '>')
		{
			input_string[*i] = '\0';
			return (1);
		}
		input_string[*i] = string[*i1];
		(*i)++;
		(*i1)++;
	}
	if (string[*i1] == '\0')
	{
		input_string[*i] = '\0';
		return (1);
	}
	return (0);
}

void	add_word(char *string, int *i1, char *split_input, int *i2)
{
	int	i;

	i = 0;
	while (string[*i1] != '\0' && string[*i1] != '<'
		&& string[*i1] != '>' && string[*i1] != '|'
		&& string[*i1] != ' ' && string[*i1] != 39
		&& string[*i1] != 34)
	{
		split_input[i] = string[*i1];
		(*i1)++;
		i++;
	}
	add_zero(string, i1, split_input, &i);
	if (string[*i1] == 34 || string[*i1] == 39)
	{
		while (1)
		{
			go_to_quote2(string, i1, split_input, &i);
			if (in(string, i1, split_input, &i) == 1)
				break ;
			if (another_q(string, i1, split_input, &i) == 1)
				break ;
		}
	}
	inc_dec(i1, i2);
}
