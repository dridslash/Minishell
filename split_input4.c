/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:27:33 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/03 11:55:57 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	g_quote(char *string, int *i, int *n, char q)
{
	while (string[*i] != q)
	{
		(*n)++;
		(*i)++;
	}
	(*i)++;
}

int	f_end(char *string, int *i, int *arr, int *arr_i)
{
	while (string[*i] != '\0')
	{
		if (string[*i] == 34 || string[*i] == 39)
			return (2);
		if (string[*i] == ' ' || string[*i] == '|'
			|| string[*i] == '<' || string[*i] == '>')
		{
			*arr_i += 1;
			return (1);
		}
		arr[*arr_i] += 1;
		(*i)++;
	}
	return (1);
}

void	go_to_quote(char *string, int *i, char q)
{
	while (string[*i] != q)
		(*i)++;
	(*i)++;
}

int	find_end(char *string, int *i, char *q)
{
	while (string[*i] != '\0')
	{
		if (string[*i] == 34 || string[*i] == 39)
		{
			*q = string[*i];
			(*i)++;
			return (0);
		}
		if (string[*i] == ' ' || string[*i] == '|'
			|| string[*i] == '<' || string[*i] == '>')
			return (1);
		(*i)++;
	}
	return (1);
}

void	add_zero(char *string, int *i1, char *split_input, int *i)
{
	if (string[*i1] == '\0' || string[*i1] == '<'
		|| string[*i1] == '>' || string[*i1] == '|'
		|| string[*i1] == ' ')
		split_input[*i] = '\0';
}
