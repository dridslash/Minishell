/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handling4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:27:06 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/01 15:49:28 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	join_mark(char **ret_string, char *split_string, int *i)
{
	(*i)++;
	*ret_string = char_join(*ret_string, '$');
	*ret_string = char_join(*ret_string, '	');
	while (split_string[*i])
	{
		*ret_string = char_join(*ret_string, split_string[*i]);
		(*i)++;
	}
	(*i)--;
}

int	le(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
