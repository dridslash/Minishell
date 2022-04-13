/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handling3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:26:57 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/13 12:25:16 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_in_env1(t_env *env, char *string)
{
	char	*ret_string;
	char	**split_string;
	int		i;
	int		j;
	int		is_in_end;

	is_in_end = check_dollar_end(&ret_string, &i, string);
	split_string = ft_split_execution(string, '$');
	while (split_string[++i] != NULL)
	{
		j = -1;
		while (split_string[i][++j] != '\0')
		{
			if (split_string[i][j] == '?' && j == 0)
				join_mark(&ret_string, split_string[i], &j);
			else
				env_join(&ret_string, split_string[i], env, &j);
		}
	}
	if (is_in_end)
		ret_string = char_join(ret_string, '$');
	free_split_in(split_string);
	return (ret_string);
}

void	env_join(char **string, char *string1, t_env *en, int *i)
{
	char	*dollar_string;
	char	*tmp;

	dollar_string = NULL;
	while (string1[*i] != '\0' && (f_isdigit(string1[*i])
			|| f_isalpha(string1[*i])))
	{
		dollar_string = char_join(dollar_string, string1[*i]);
		(*i)++;
	}
	tmp = dollar_string;
	if (dollar_string)
		dollar_string = search_in_env(&en, dollar_string);
	if (tmp)
		free(tmp);
	if (dollar_string != NULL)
		*string = t_strjoin(*string, dollar_string);
	if (dollar_string)
		free(dollar_string);
	while (string1[*i] != '\0')
	{
		*string = char_join(*string, string1[*i]);
		(*i)++;
	}
	(*i)--;
}

int	f_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	f_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	check_dollar_end(char **str, int *i, char *string)
{
	int	j;

	j = 0;
	*str = NULL;
	*i = -1;
	while (string[j] != '\0')
		j++;
	if (string[j - 1] == '$')
		return (1);
	return (0);
}
