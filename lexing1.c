/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:19:59 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/19 11:55:40 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char **split_first_input(char *input)
{
	int		stop;
	int		i;
	char	**return_value;

	i = 0;
	stop = 0;
	return_value = NULL;
	while (input[i] != '\0')
	{
		if (input[i] == '|')
			return_value = push(input, i, return_value, &stop);
		i++;
	}
}
