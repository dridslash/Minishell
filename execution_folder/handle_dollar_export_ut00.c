/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_export_ut00.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:34:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/11 17:10:32 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

char	*search_in_env(t_env **envv, char *your_var)
{
	t_env	*aff;
	char	*tmp;
	char	*tmp2;

	aff = (*envv);
	while (aff)
	{
		tmp = get_name_of_env_var(aff->path_env);
		tmp2 = get_name_of_env_var(your_var);
		if (ft_strcmp(tmp, tmp2) == 0)
		{
			free(tmp);
			free(tmp2);
			return (get_after_equal(aff->path_env));
		}
		aff = aff->next_env;
		free(tmp);
		free(tmp2);
	}
	return (ft_strdup_execution(""));
}

int	check_exit_status(t_cmd *cmd)
{
	int		index_tmp;
	int		i;
	char	*holder;

	index_tmp = 0;
	i = 0;
	holder = cmd->cmd_w_arg[index_tmp + 1];
	if (check_if_there_is_a_dollar(cmd->cmd_w_arg[index_tmp + 1]) == 1)
	{
		while (holder[i])
		{
			if ((holder[i] == '$' && holder[i + 1] == '?')
				&& i > get_equal_index(holder))
				return (1);
				i++;
		}
	}
	return (0);
}

int	check_is_dollar_after_equal(t_cmd *cmd)
{
	int		index_tmp;
	int		i;
	char	*holder;

	index_tmp = 0;
	i = 0;
	holder = cmd->cmd_w_arg[index_tmp + 1];
	if (check_if_there_is_a_dollar(cmd->cmd_w_arg[index_tmp + 1]) == 1)
	{
		while (holder[i])
		{
			if (holder[i] == '$' && i > get_equal_index(holder))
				return (1);
				i++;
		}
	}
	return (0);
}
