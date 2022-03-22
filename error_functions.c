/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:23:27 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/22 18:25:25 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	check_errors(char *input)
{
	int	i;

	if (pipe_beggining(input) == 0)
		return (0);
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '|' && !check_after_pipe(input, &i))
			return (0);
		else if (input[i] == '>' && !check_out_red(input, &i))
			return (0);
		else if (input[i] == '<' && !check_in_red(input, &i))
			return (0);
		else if (input[i] == 34 && !check_d_quotes(input, &i))
			return (0);
		else if (input[i] == 39 && !check_s_quotes(input, &i))
			return (0);
		i++;
	}
	return (1);
}

int	check_in_red(char *input, int *i)
{
	(*i)++;
	if (input[*i] == '<')
		(*i)++;
	while (input[*i] == ' ')
		(*i)++;
	if (input[*i] == '|' || input[*i] == '\0' || input[*i] == '>'
		|| input[*i] == '<')
	{
		write(2, "Input Error !\n", 14);
		return (0);
	}
	(*i)--;
	return (1);
}

int	check_out_red(char *input, int *i)
{
	(*i)++;
	if (input[*i] == '>')
		(*i)++;
	while (input[*i] == ' ')
		(*i)++;
	if (input[*i] == '\0' || input[*i] == '\n'
		|| input[*i] == '|' || input[*i] == '<'
		|| input[*i] == '>')
	{
		write(2, "Input Error !\n", 14);
		return (0);
	}
	(*i)--;
	return (1);
}

int	check_after_pipe(char *input, int *i)
{
	(*i)++;
	while (input[*i] == ' ')
		(*i)++;
	if (input[*i] == '|')
	{
		write(2, "Input Error !\n", 14);
		return (0);
	}
	(*i)--;
	return (1);
}
