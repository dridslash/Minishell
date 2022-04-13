/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:28:19 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/13 12:41:09 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_d_quotes(char *input, int *i)
{
	(*i)++;
	while (input[*i] != '\0')
	{
		if (input[*i] == 34)
			return (1);
		(*i)++;
	}
	write(2, "Non closed double quotes !\n", 27);
	return (0);
}

int	check_s_quotes(char *input, int *i)
{
	(*i)++;
	while (input[*i] != '\0')
	{
		if (input[*i] == 39)
			return (1);
		(*i)++;
	}
	write(2, "Non closed single quotes !\n", 27);
	return (0);
}

int	pipe_beggining(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	if (input[i] == '\0')
	{
		free (input);
		return (0);
	}
	if (input[i] == '|')
	{
		free(input);
		write(2, "Input Error !\n", 14);
		return (0);
	}
	else if (input[i] == '\0')
		return (0);
	return (1);
}
