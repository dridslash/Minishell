/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handling1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:26:46 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/12 21:39:00 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
//EXEC
#include "exec_test.h"
//EXEC

void	check_env(char *input, char **split_input, t_env *env)
{
	int	i1;
	int	i2;

	i2 = 0;
	i1 = 0;
	while (input[i1] != '\0')
	{
		if (input[i1] == ' ')
			skip_spaces(input, &i1);
		else if (input[i1] == '|')
			i2++;
		else if (input[i1] == '<' || input[i1] == '>')
			skip_red2(input, &i1, &i2);
		else if (ft_strcmp(split_input[i2], "export") == 0
			&& split_input[i2][6] == '\0')
			skip_for_exp(input, &i1, &i2);
		else
		{
			check_dollar(input, &i1, &split_input[i2], env);
			i2++;
		}
		i1++;
	}
}

void	skip_red2(char *input, int *i1, int *i2)
{
	int	tmp;

	tmp = 0;
	if (input[*i1] == '<' && input[*i1 + 1] == '<')
	{
		*i1 += 2;
		skip_spaces(input, i1);
		(*i1)++;
		skip_words(input, i1, &tmp);
		*i2 += 2;
	}
	else
	{
		(*i1)++;
		if (input[*i1] == '<' || input[*i1] == '>')
			(*i1)++;
		(*i2)++;
		(*i1)--;
	}
}

void	check_dollar(char *input, int *i1, char **split_input, t_env *env)
{
	char	*string;

	string = NULL;
	while (input[*i1] != '\0' && input[*i1] != ' '
		&& input[*i1] != '>' && input[*i1] != '<' && input[*i1] != '|')
	{
		if (input[*i1] == '\"')
			get_dol_double_q(input, i1, &string, env);
		else if (input[*i1] == '$')
			get_dollar1(input, i1, &string, env);
		else if (input[*i1] == '\'')
			get_single_q_dollar(input, i1, &string);
		else
			string = char_join(string, input[*i1]);
		*i1 += 1;
	}
	(*i1)--;
	free(*split_input);
	*split_input = string;
}

void	get_dollar1(char *input, int *i1, char **string, t_env *env)
{
	char	*s;
	char	*t;

	s = NULL;
	while (input[*i1] != '\0' && input[*i1] != ' '
		&& input[*i1] != '>' && input[*i1] != '<'
		&& input[*i1] != '|' && input[*i1] != 34 && input[*i1] != 39)
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

void	get_dol_double_q(char *input, int *i1, char **string, t_env *env)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	(*i1)++;
	if (input[*i1] == '\"')
		*string = char_join(*string, '\0');
	while (input[*i1] != '\"' && input[*i1] != '\0')
	{
		if (input[*i1] == '$')
			get_after_q2(input, i1, string, env);
		else
			*string = char_join(*string, input[*i1]);
		(*i1)++;
	}
	return ;
}
