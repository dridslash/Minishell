/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:07:29 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/19 16:12:09 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	main(void)
{
	char	*input;
	char	**input_split;

	while (1)
	{
		input = readline("$> ");
		check_errors(input);
		input_split = split_input(input);
	}
}
