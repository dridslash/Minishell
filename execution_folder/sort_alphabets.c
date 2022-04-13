/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alphabets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:56:41 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 22:32:42 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	size_of_list(t_env **envv)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = (*envv);
	while (tmp)
	{
		i++;
		tmp = tmp->next_env;
	}
	return (i);
}

void	ft_fill_array(t_env **envv, char **holder, t_env *pl)
{
	int	i;

	i = 0;
	while (i < size_of_list(envv) && pl)
	{
		holder[i] = ft_strdup_execution(pl->path_env);
		i++;
		pl = pl->next_env;
	}
	holder[i] = NULL;
}

void	sort_alpha_helper(char **holder)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (holder[i])
	{
		j = i + 1;
		while (holder[j])
		{
			if (ft_strcmp(&holder[i][0], &holder[j][0]) > 0)
			{
				tmp = holder[i];
				holder[i] = holder[j];
				holder[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort_alpha(t_env **envv, int out_file)
{
	char	**holder;
	t_env	*pl;
	int		i;

	pl = (*envv);
	holder = (char **) malloc(sizeof(char *) * (size_of_list(envv) + 1));
	ft_fill_array(envv, holder, pl);
	sort_alpha_helper(holder);
	i = 0;
	while (holder[i])
	{
		write(out_file, "declare -x ", 12);
		write (out_file, holder[i], ft_strlen(holder[i]));
		write(out_file, "\n", 1);
		i++;
	}
	free_split_in(holder);
}
