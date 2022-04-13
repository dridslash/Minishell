/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:03:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 12:58:50 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	execute_cmds_close_files(int in_file,
int out_file, int fds, int *pipes)
{
	int	i;

	i = 0;
	dup2(in_file, 0);
	dup2(out_file, 1);
	while (i < fds)
	{
		close(pipes[i]);
		i++;
	}
}

void	create_pipes(int **pipes, int how_many_cmds)
{
	int	iterate;
	int	*holder_pipe;

	holder_pipe = malloc(sizeof(int) * (how_many_cmds - 1) * 2);
	iterate = 0;
	while ((iterate < (how_many_cmds - 1) * 2))
	{
		pipe(&holder_pipe[iterate]);
		iterate += 2;
	}
	*pipes = holder_pipe;
}

int	count_size_of_list(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd != NULL)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}

void	close_pipe_wait(int *pipes, int original_cmds)
{
	int	j;
	int	status;

	j = 0;
	status = 0;
	while (j < (original_cmds - 1) * 2)
	{
		close(pipes[j]);
		j++;
	}
	j = 0;
	while (j < original_cmds)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED (status))
		g_exit_status = WEXITSTATUS(status);
	j++;
	}
}

int	main_execution_func(t_cmd *cmd, t_env **env_var)
{
	int		*pipes;
	int		original_cmds;

	pipes = NULL;
	original_cmds = count_size_of_list(cmd);
	if (original_cmds > 1 && is_there_a_her_doc(cmd) == 0)
	{
		create_pipes(&pipes, original_cmds);
		execute_commands(cmd, env_var, pipes, original_cmds);
		close_pipe_wait(pipes, original_cmds);
	}
	else if (original_cmds == 1 && is_there_a_her_doc(cmd) == 0)
		return (execute_command(cmd, env_var));
	else if (is_there_a_her_doc(cmd))
	{
		create_pipes(&pipes, original_cmds);
		execute_her_docs(cmd, (*env_var), original_cmds, pipes);
		close_pipe_wait(pipes, original_cmds);
	}
	free(pipes);
	return (0);
}
