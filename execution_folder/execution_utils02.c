/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:30:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/05 18:08:04 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	execution_help_of_hlp(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		// if (holder_nodes->out_file_op > 1)
		// {
		// 	execute_cmds_close_files(holder_nodes->in_file_op,
		// 	holder_nodes->out_file_op,
		// 	(holder_nodes->size_of_list - 1) * 2, pipes);
		// }
		// if (holder_nodes->in_file_op > -1)
		// {
		// 	execute_cmds_close_files(holder_nodes->in_file_op,
		// 	holder_nodes->out_file_op,
		// 	(holder_nodes->size_of_list - 1) * 2, pipes);
		// }
		// else
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
	}
	else
		execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
}

void	execution_help_of_hlp_two(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
	}
	else
		execute_cmds_close_files(holder_nodes->in_file_op,
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
}

void	execution_hlp_main_one(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes)
{
	if (iterate + 1 == holder_nodes->size_of_list)
	{
		execution_help_of_hlp(holder_nodes, iterate_for_fds, iterate, pipes);
	}
	else
	{
		execution_help_of_hlp_two(holder_nodes,
			iterate_for_fds, iterate, pipes);
	}
}

void	execution_hlp_main_two(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
	}
	else
	{
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
}

void	exectuion_hlp_main_three(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
	}
	else
	{
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
}
