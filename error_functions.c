/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:23:27 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/19 13:21:32 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	check_errors(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '|')
			check_after_pipe(input, &i);
		else if (input[i] == '>')
			check_after_output_redirection(input, &i);
		else if (input[i] == '<')
			check_after_input_redirection(input, &i);
		i++;
	}
}

void	check_after_input_redirection(char *input, int *i)
{
	(*i)++;
	if (input[*i] == '<')
		(*i)++;
	while (input[*i] == ' ')
		(*i)++;
	if (input[*i] == '|' || input[*i] == '\0' || input[*i] == '>'
		|| input[*i] == '<')
		exit_error();
}

void	check_after_output_redirection(char *input, int *i)
{
	(*i)++;

	if (input[*i] == '>')
		(*i)++;
	while (input[*i] == ' ')
		(*i)++;
	if (input[*i] == '\0' || input[*i] == '\n'
		|| input[*i] == '|' || input[*i] == '<'
		|| input[*i] == '>')
		exit_error();
}

void	check_after_pipe(char *input, int *i)
{
	(*i)++;
	while (input[*i] == ' ')
		(*i)++;
	if (input[*i] == '|')
		exit_error();
}

void	exit_error(void)
{
	printf("Input Error !\n");
	exit(EXIT_FAILURE);
}
