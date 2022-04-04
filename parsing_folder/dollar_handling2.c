/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handling2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:26:51 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/04 13:24:29 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	get_single_q_dollar(char *input, int *i1, char **string)
{
	(*i1)++;
	if (input[*i1] == '\'')
		*string = char_join(*string, '\0');
	while (input[*i1] != '\'')
	{
		*string = char_join(*string, input[*i1]);
		(*i1)++;
	}
}

void	get_after_q2(char *input, int *i1, char **string, t_env *env)
{
	char	*s;
	char	*t;

	s = NULL;
	while (input[*i1] != '\"')
	{
		s = char_join(s, input[*i1]);
		(*i1)++;
	}
	(*i1)--;
	t = s;
	s = search_in_env1(env, s);
	free(t);
	if (s == NULL)
		return ;
	*string = t_strjoin(*string, s);
	free(s);
}
