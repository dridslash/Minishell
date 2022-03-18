/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:19:59 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/18 15:02:52 by oessayeg         ###   ########.fr       */
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

char **push(char *input, int i, char **pt, int *stop)
{
	char **ret_string;

	if (return_value == NULL)
		return_value = ;
	ret_string = alloc_space(input, i, *stop, pt);
}

char **alloc_space(char *input, int i, int stop, char *pt)
{
	char **ret;

	if (pt == NULL)
		ret = malloc(sizeof(char) * 2);
	else
		ret = malloc(sizeof(char) * len_of(pt) + 1);
	return (ret);
}

int	len_of(char **string){
}
