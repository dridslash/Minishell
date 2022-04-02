/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:09:52 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/02 20:22:56 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void execution_helper_one(t_cmd *holder_nodes, int iterate_for_fds, int iterate, int *pipes)
{
	if (iterate == 0)
			{
				if (iterate + 1 == holder_nodes->size_of_list)
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
						execute_cmds_close_files(holder_nodes->in_file_op,
							holder_nodes->out_file_op,
							(holder_nodes->size_of_list - 1) * 2, pipes);
					}
				}
				else
				{
					if (holder_nodes->how_many_here_doc > 0)
					{
						execute_cmds_close_files(holder_nodes->fd_her_doc[0],
							pipes[iterate_for_fds + 1],
							( holder_nodes->size_of_list - 1) * 2, pipes);
						close(holder_nodes->fd_her_doc[0]);
						close(holder_nodes->fd_her_doc[1]);
					}
					else
					{
						execute_cmds_close_files(holder_nodes->in_file_op,
							pipes[iterate_for_fds + 1],
							( holder_nodes->size_of_list - 1) * 2, pipes);
					}
				}
			}
			else if (iterate + 1 ==  holder_nodes->size_of_list)
			{
				if (holder_nodes->how_many_here_doc > 0)
				{
					execute_cmds_close_files(holder_nodes->fd_her_doc[0],
						holder_nodes->out_file_op,
						( holder_nodes->size_of_list - 1) * 2, pipes);
					close(holder_nodes->fd_her_doc[0]);
					close(holder_nodes->fd_her_doc[1]);
				}
				else
				{
					execute_cmds_close_files(pipes[iterate_for_fds - 2],
						holder_nodes->out_file_op,
						( holder_nodes->size_of_list - 1) * 2, pipes);
				}
			}
			else
			{
				if (holder_nodes->how_many_here_doc > 0)
				{
					execute_cmds_close_files(holder_nodes->fd_her_doc[0],
						pipes[iterate_for_fds + 1],
						( holder_nodes->size_of_list - 1) * 2, pipes);
					close(holder_nodes->fd_her_doc[0]);
					close(holder_nodes->fd_her_doc[1]);
				}
				else
				{
					execute_cmds_close_files(pipes[iterate_for_fds - 2],
						pipes[iterate_for_fds + 1],
						( holder_nodes->size_of_list - 1) * 2, pipes);
				}
			}
}	

int	execute_her_docs(t_cmd *cmd, t_env *env_var, int original_cmds , int *pipes)
{
	int		iterate;
	int		iterate_for_fds;
	int		iterate_her_docs;
	int		*pids;
	t_cmd	*holder_nodes;

	holder_nodes = cmd;
	pids = malloc(sizeof(int) * original_cmds);
	iterate = 0;
	iterate_for_fds = 0;
	while (holder_nodes)
	{
		her_doc_helper_main(holder_nodes, env_var, original_cmds);
		holder_nodes = holder_nodes->next;
	}
	holder_nodes = cmd;
	while (iterate < original_cmds && (holder_nodes))
	{
		pids[iterate] = fork();
		if (pids[iterate] == 0)
		{
			holder_nodes->size_of_list = original_cmds;
			execution_helper_one(holder_nodes, iterate_for_fds,iterate,pipes);
			execve(get_path(holder_nodes->cmd_w_arg[0], env_var),
				holder_nodes->cmd_w_arg, NULL);
			return (0);
		}
		iterate++;
		iterate_for_fds += 2;
		holder_nodes = holder_nodes->next;
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