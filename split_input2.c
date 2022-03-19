/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:11:10 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/19 16:12:54 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	skip_quotes(char *string, int *i, int *word_count)
{
	*word_count += 1;
	(*i)++;
	while (string[*i] == 34 || string[*i] == 39)
		(*i)++;
	if (find_quote(string, *i) == 0)
	{
		(*i)--;
		return ;
	}
	while (string[*i] != 34 && string[*i] != 39
		&& string[*i] != '\0')
		(*i)++;
	while (string[*i] == 34 || string[*i] == 39)
		(*i)++;
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
