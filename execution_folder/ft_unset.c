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

// #include "../parsing_folder/exec_test.h"
// #include "../parsing_folder/minishell.h"

// void	free3(char *s1, char *s2, t_env *n)
// {
// 	free(s1);
// 	free(s2);
// 	if (n != NULL)
// 		free(n);
// }

// int	ft_unset_helper(t_env **env_var, t_cmd *cmd, int index, t_env *looper)
// {
// 	t_env	*prev;
// 	t_env	*this;
// 	t_env	*tmp;
// 	char	*tmp2;
// 	char	*tmp1;

// 	prev = malloc(sizeof(t_env));
// 	tmp1 = get_name_of_env_var(looper->path_env);
// 	tmp2 = get_name_of_env_var(cmd->cmd_w_arg[index + 1]);
// 	if (ft_strcmp(tmp1, tmp2) == 0)
// 	{
// 		if (get_index_of_env_var(env_var, looper->path_env) == 0)
// 		{
// 			(*env_var) = looper->next_env;
// 			//looper->next_env = NULL;
// 			free3(tmp1, tmp2, NULL);
// 			return (1);
// 		}
// 		else
// 		{
// 			tmp = looper;
// 			prev->next_env = tmp->next_env;
// 			tmp->next_env = NULL;
// 			free3(tmp1, tmp2, NULL);
// 			return (1);
// 		}
// 	}
// 	prev = looper;
// 	return (0);
// }

// void	ft_unset(t_env **env_var, t_cmd *cmd)
// {
// 	t_env	*looper;
// 	int		index;

// 	looper = (*env_var);
// 	index = 0;
// 	if (cmd->cmd_w_arg[index] != NULL
// 		&& (ft_strcmp(cmd->cmd_w_arg[index], "unset") == 0))
// 	{
// 		if (cmd->cmd_w_arg[index + 1] != NULL)
// 		{
// 			while (looper != NULL)
// 			{
// 				if (ft_unset_helper(env_var, cmd, index, looper))
// 						break;
// 				looper = looper->next_env;
// 			}
// 		}
// 	}
// 	exit_status = 0;
// }

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_unset_helper(t_env **env_var, t_cmd *cmd, int index, t_env *looper)
{
	t_env	*prev;
	t_env	*tmp;
	char	*tp;

	tp = get_name_of_env_var(looper->path_env);
	if ((cmd->cmd_w_arg[index] != NULL) && (ft_strcmp(tp, cmd->cmd_w_arg[index]) == 0))
	{
		if (get_index_of_env_var(env_var, looper->path_env) == 0)
		{
			tmp = (*env_var);
			(*env_var) = (*env_var)->next_env;
			free(tmp);
		}
		else
		{
			tmp = looper;
			prev->next_env = tmp->next_env;
			free(tmp->path_env);
			free(tmp);
		}
	}
	free(tp);
	prev = looper;
}

void call_in_loop(t_env **env_var, t_cmd *cmd, int index, t_env *looper)
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
	exit_status = 0;
}