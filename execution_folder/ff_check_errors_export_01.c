/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_check_errors_export_01.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:46:17 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/11 12:18:16 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	check_simple_quote(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i] != '=')
	{
		if (your_path[i + 1] == '=' && your_path[i + 2] == '=')
			return (10);
		if (your_path[i] == '\'')
		{
			return (10);
		}
		i++;
	}
	return (0);
}

int	check_empty_path_name(char *your_path)
{
	if (get_equal_index(your_path) == 0)
	{
		return (9);
	}
	return (0);
}

int	check_if_there_is_a_dollar(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i])
	{
		if (your_path[i] == '$' && i != 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_is_exportable(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i] != '=')
	{
		if (((your_path[i] == '$') && (your_path[i + 1] == '$'))
			|| ((your_path[i] == '$') && i == 0))
			return (11);
		if (((your_path[i] == '$') && (your_path[i + 1] == '=')))
			return (11);
		if (ft_isascii(your_path[i]) && your_path[i] != '$')
		{
			if ((ft_isdigit(your_path[i]) == 0)
				&& (ft_isalpha(your_path[i]) == 0) && (your_path[i] != '='))
			{
				if ((your_path[i] == '+'
						&& (your_path[i + 1] == '=')) || (your_path[i] == ' '))
					return (0);
				else
					return (11);
			}
		}
		i++;
	}
	return (0);
}

int	check_errors_export(char *your_path)
{
	int	i;

	i = 0;
	i = check_simple_quote(your_path);
	if (i > 0)
		return (i);
		i = check_empty_path_name(your_path);
	if (i > 0)
		return (i);
		i = check_for_space(your_path);
	if (i > 0)
		return (i);
		i = check_for_digits(your_path);
	if (i > 0)
		return (i);
		i = check_for_minus(your_path);
	if (i > 0)
		return (i);
		i = check_for_plus(your_path);
	return (i);
}
