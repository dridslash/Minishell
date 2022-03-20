/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:11:10 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/20 12:36:42 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	skip_quotes(char *string, int *i, int *word_count)
{
	char	val;

	if (string[*i] == 34)
		val = 34;
	else
		val = 39;
	(*i)++;
	while (string[*i] != '\0')
	{
		if (string[*i] == val && (string[*i + 1] == ' '
			|| string[*i + 1] == '\0'))
		{
			*word_count += 1;
			return ;
		}
		(*i)++;
	}
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
