/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:11:09 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/02 15:25:00 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	execut_helper_one(t_cmd *holder_nodes,
			int iterate, int *pipes, int iterate_for_fds)
{
	if (iterate == 0)
	{
		execute_cmds_close_files(holder_nodes->in_file_op,
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	else if (iterate + 1 == holder_nodes->size_of_list)
	{
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	else
	{
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	return (0);
}

int	execute_commands(t_cmd *cmd, t_env *env_var, int *pipes, int original_cmds)
{
	t_cmd	*holder_nodes;
	int		iterate;
	int		iterate_for_fds;
	int		*pids;

	holder_nodes = cmd;
	pids = malloc(sizeof(int) * original_cmds);
	iterate = 0;
	iterate_for_fds = 0;
	while (iterate < original_cmds && (holder_nodes))
	{
		holder_nodes->size_of_list = original_cmds;
		pids[iterate] = fork();
		if (pids[iterate] == 0)
		{
			execut_helper_one(holder_nodes, iterate, pipes, iterate_for_fds);
			execve(get_path(holder_nodes->cmd_w_arg[0], env_var),
				holder_nodes->cmd_w_arg, NULL);
		}
		iterate++;
		iterate_for_fds += 2;
		holder_nodes = holder_nodes->next;
	}
	return (0);
}

int	execute_command(t_cmd *cmd, t_env *env_var, int original_cmds)
{
	int	pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		dup2(cmd->in_file_op, 0);
		dup2(cmd->out_file_op, 1);
		execve(get_path(cmd->cmd_w_arg[0], env_var), cmd->cmd_w_arg, NULL);
		return (0);
	}
	waitpid(pid, NULL, 0);
	return (0);
}