/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:19:59 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/18 13:02:57 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char **split_first_input(char *input)
{
	int		i;
	char	**return_value;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '|')
			push_before_pipe(input, i, return_value);
		i++;
	}
}

int	is_del(char *input, int index)
{
	if (input[i] == '|' || input[i] == '>')
		return (1);
	return (0);
}
