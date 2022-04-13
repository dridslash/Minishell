/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handling4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:27:06 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/12 21:40:01 by oessayeg         ###   ########.fr       */
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

void	skip_for_exp(char *input, int *i1, int *i2)
{
	int	tmp;

	tmp = 0;
	(*i2) += 1;
	(*i1) += 6;
	while (input[*i1] != '<' && input[*i1] != '>' && input[*i1] != '|'
		&& input[*i1] != '\0')
	{
		if (input[*i1] == ' ')
		{
			skip_spaces(input, i1);
			(*i1)++;
		}
		else
		{
			skip_words(input, i1, &tmp);
			(*i2) += 1;
			(*i1)++;
		}
	}
	(*i1)--;
}
