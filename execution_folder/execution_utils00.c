/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:09:52 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/03 10:36:11 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	try_help(t_cmd *holder_nodes, t_env *env_var, int original_cmds)
{
	while (holder_nodes)
	{
		her_doc_helper_main(holder_nodes, env_var, original_cmds);
		holder_nodes = holder_nodes->next;
	}
}

void	execution_helper_main(t_cmd *holder_nodes,
	int iterate_for_fds, int iterate, int *pipes)
{
	if (iterate == 0)
	{
		execution_hlp_main_one(holder_nodes, iterate_for_fds, iterate, pipes);
	}
	else if (iterate + 1 == holder_nodes->size_of_list)
	{
		execution_hlp_main_two(holder_nodes, iterate_for_fds, iterate, pipes);
	}
	else
	{
		exectuion_hlp_main_three(holder_nodes, iterate_for_fds, iterate, pipes);
	}
}

void	iterate_func(int *iterate, int *iterate_for_fds, t_cmd **holder_nodes)
{
	(*iterate)++;
	(*iterate_for_fds) += 2;
	(*holder_nodes) = (*holder_nodes)->next;
}

int	execute_her_docs(t_cmd *cmd, t_env *env_var, int original_cmds, int *pipes)
{
	int		iterate;
	int		iterate_for_fds;
	int		*pids;
	t_cmd	*holder_nodes;

	holder_nodes = cmd;
	pids = malloc(sizeof(int) * original_cmds);
	iterate = 0;
	iterate_for_fds = 0;
	try_help(holder_nodes, env_var, original_cmds);
	while (iterate < original_cmds && (holder_nodes))
	{
		pids[iterate] = fork();
		if (pids[iterate] == 0)
		{
			holder_nodes->size_of_list = original_cmds;
			execution_helper_main(holder_nodes,
				iterate_for_fds, iterate, pipes);
			execve(get_path(holder_nodes->cmd_w_arg[0], env_var),
				holder_nodes->cmd_w_arg, NULL);
			return (0);
		}
		iterate_func(&iterate, &iterate_for_fds, &holder_nodes);
	}
	return (0);
}

int	is_there_a_her_doc(t_cmd	*cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (tmp->how_many_here_doc > 0)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
