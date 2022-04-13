/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:09:52 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 15:43:50 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	try_help(t_cmd *holder_nodes)
{
	while (holder_nodes)
	{
		her_doc_helper_main(holder_nodes);
		holder_nodes = holder_nodes->next;
	}
}

void	execution_helper_main(t_cmd *holder_nodes,
	int *it_it_fds, int *pipes, t_env **env_var)
{
	handle_q_mark(holder_nodes);
	if (it_it_fds[0] == 0)
	{
		execution_hlp_main_one(holder_nodes, it_it_fds, pipes, env_var);
	}
	else if (it_it_fds[0] + 1 == holder_nodes->size_of_list)
	{
		execution_hlp_main_two(holder_nodes, it_it_fds, pipes, env_var);
	}
	else
	{
		exectuion_hlp_main_three(holder_nodes, it_it_fds, pipes, env_var);
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
	int		it_it_fd[2];

	holder_nodes = cmd;
	pids = malloc(sizeof(int) * original_cmds);
	in_ss(&iterate, &iterate_for_fds);
	call_signal_try_help(holder_nodes);
	while (iterate < original_cmds && (holder_nodes))
	{
		it_it_fd[0] = iterate;
		it_it_fd[1] = iterate_for_fds;
		pids[iterate] = fork();
		if (pids[iterate] == 0)
		{
			holder_nodes->size_of_list = original_cmds;
			execute_her_docc(holder_nodes, env_var, it_it_fd, pipes);
			return (0);
		}
		iterate_func(&iterate, &iterate_for_fds, &holder_nodes);
	}
	free(pids);
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
