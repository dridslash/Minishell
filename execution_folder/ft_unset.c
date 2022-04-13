/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:58:06 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 11:50:54 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	unset_else(t_env *looper, t_env **prev, t_env *tmp, char **tp)
{
	tmp = looper;
	(*prev)->next_env = tmp->next_env;
	free(tmp->path_env);
	free(tmp);
	free(*tp);
	return ;
}

void	ft_unset_helper(t_env **env_var, t_cmd *cmd, int index, t_env *looper)
{
	t_env	*prev;
	t_env	*tmp;
	char	*tp;

	tmp = NULL;
	tp = get_name_of_env_var(looper->path_env);
	if ((cmd->cmd_w_arg[index] != NULL)
		&& (ft_strcmp(tp, cmd->cmd_w_arg[index]) == 0))
	{
		if (get_index_of_env_var(env_var, looper->path_env) == 0)
		{
			tmp = (*env_var);
			(*env_var) = (*env_var)->next_env;
			free(tmp);
			return ;
		}
		else
		{
			unset_else(looper, &prev, tmp, &tp);
			return ;
		}
	}
	free(tp);
	prev = looper;
}

void	call_in_loop(t_env **env_var, t_cmd *cmd, int index, t_env *looper)
{
	while (looper != NULL)
	{
		ft_unset_helper(env_var, cmd, index, looper);
				looper = looper->next_env;
	}
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
		while (cmd->cmd_w_arg[index] != NULL)
		{
			call_in_loop(env_var, cmd, index, looper);
			index++;
		}
	}
	g_exit_status = 0;
}
