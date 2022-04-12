/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:43:10 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/09 14:07:38 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	get_equal_index(char *table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		if (table[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_after_equal(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i])
	{
		if (your_path[i] == '=')
		{
			return (ft_strdup_execution(&your_path[i + 1]));
		}
		i++;
	}
	return (NULL);
}

void	append_env_vr(t_env **envv, char *var)
{
	t_env	*tmp;
	char	**holder_first;

	tmp = (*envv);
	while (tmp)
	{
		holder_first = ft_split_execution(tmp->path_env, '=');
		if (ft_strcmp(holder_first[0], var) == 0)
		{
			ft_strjoin_non_free(tmp->path_env, var);
			break ;
		}
		tmp = tmp->next_env;
	}
}

char	*get_name_of_env_var(char *tb)
{
	int		i;
	int		index_tmp;
	char	*chr;

	i = 0;
	chr = ft_strdup_execution(tb);
	index_tmp = 2;
	while (chr[i])
	{
		if (chr[i] == '=' || (chr[i] == '+' && chr[i + 1] == '='))
		{
			chr[i] = '\0';
			break ;
		}
		i++;
	}
	return (chr);
}

char	*get_after_dollar(char *your_path)
{
	int	i;

	i = 0;
	while (your_path[i])
	{
		if (your_path[i] == '$')
		{
			return (ft_strdup_execution(&your_path[i + 1]));
		}
		i++;
	}
	return (NULL);
}
