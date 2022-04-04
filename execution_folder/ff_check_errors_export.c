/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_check_errors_export.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:44:36 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 14:50:58 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	check_for_minus(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i] != '=')
	{
		if (your_path[i] == '-' && (i < get_equal_index(your_path)))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_for_plus(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i] != '=')
	{
		if (your_path[i] == '+' && your_path[i + 1] != '=')
		{
			return (2);
		}
		i++;
	}
	return (0);
}

int	check_for_plus_to_export(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i] != '=')
	{
		if (your_path[i] == '+' && your_path[i + 1] == '=')
		{
			return (8);
		}
	i++;
	}
	return (0);
}

int	check_for_digits(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i] != '=')
	{
		if (ft_isdigit(your_path[i]) && i == 0)
		{
			return (3);
		}
		i++;
	}
	return (0);
}

int	check_for_space(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i] != '=')
	{
		if (your_path[i] == ' ' && i > get_equal_index(your_path))
		{
			return (7);
		}
		else if (your_path[i] == ' ' && i < get_equal_index(your_path))
		{
			return (4);
		}
		i++;
	}
	return (0);
}
