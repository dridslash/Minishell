/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:58:06 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/11 10:33:13 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_unset_helper(t_env **env_var, t_cmd *cmd, int index, t_env *looper)
{
	t_env	*prev;
	t_env	*this;
	t_env	*tmp;

	if (ft_strcmp(get_name_of_env_var(looper->path_env),
			get_name_of_env_var(cmd->cmd_w_arg[index + 1])) == 0)
	{
		if (get_index_of_env_var(env_var, looper->path_env) == 0)
		{
			this = looper->next_env;
			(*env_var) = this;
			looper->next_env = NULL;
			free(looper);
			return ;
		}
		else
		{
			tmp = looper;
			prev->next_env = tmp->next_env;
			tmp->next_env = NULL;
			free(tmp);
		}
	}
	prev = looper;
}

void	ft_unset(t_env **env_var, t_cmd *cmd)
{
	t_env	*looper;
	int		index;

	looper = (*env_var);
	index = 0;
	if (cmd->cmd_w_arg[index] != NULL
		&& (ft_strcmp(cmd->cmd_w_arg[index], "unset") == 0))
	{
		if (cmd->cmd_w_arg[index + 1] != NULL)
		{
			while (looper != NULL)
			{
				ft_unset_helper(env_var, cmd, index, looper);
				looper = looper->next_env;
			}
		}
		else
		{
		}
	}
	exit_status = 0;
}
