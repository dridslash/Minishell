/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:58:06 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/14 10:46:02 by mnaqqad          ###   ########.fr       */
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
	free (*tp);
	return ;
}

void	unset_if(t_env **env_var, t_env *tmp, char **tp)
{
	tmp = (*env_var);
	(*env_var) = (*env_var)->next_env;
	free(tmp->path_env);
	free(tmp);
	free(*tp);
}

int	ft_unset_helper(t_env **env_var, t_cmd *cmd, int index, t_env *looper)
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
			unset_if(env_var, tmp, &tp);
			return (1);
		}
		else
		{
			unset_else(looper, &prev, tmp, &tp);
			return (1);
		}
	}
	free(tp);
	prev = looper;
	return (0);
}

void	call_in_loop(t_env **env_var, t_cmd *cmd, int index, t_env *looper)
{
	while (looper != NULL)
	{
		if (ft_unset_helper(env_var, cmd, index, looper) == 1)
			break ;
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
