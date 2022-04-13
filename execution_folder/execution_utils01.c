/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:11:09 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 18:52:00 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	execut_helper_one(t_cmd *holder_nodes,
			int *it_it_fds, int *pipes, t_env **env_var)
{
	handle_q_mark(holder_nodes);
	if (it_it_fds[0] == 0)
	{
		func_built_ins_send_redi(holder_nodes, pipes, it_it_fds[1], env_var);
	}
	else if (it_it_fds[0] + 1 == holder_nodes->size_of_list)
	{
		func_built_ins_send_redi_two(holder_nodes,
			pipes, it_it_fds[1], env_var);
	}
	else
	{
		func_built_ins_send_redi_three(holder_nodes,
			pipes, it_it_fds[1], env_var);
	}
	return (1);
}

void	help_for_execute_commands(t_cmd *holder_nodes,
	t_env **env_var, int *pipes, int *it_it_fds)
{
	if (access(holder_nodes->cmd_w_arg[0], X_OK) == -1
		&&ft_error(holder_nodes, (*env_var)))
		exit(g_exit_status);
	if (holder_nodes->out_file_op == -100
		|| holder_nodes->in_file_op == -100
		|| holder_nodes->cmd_w_arg == NULL)
		exit (1);
	if (execut_helper_one(holder_nodes, it_it_fds, pipes, env_var) != 0)
		execve(get_path(holder_nodes->cmd_w_arg[0], (*env_var)),
			holder_nodes->cmd_w_arg, fill_envp((*env_var)));
	exit (0);
}

int	execute_commands(t_cmd *cmd, t_env **env_var, int *pipes, int original_cmds)
{
	t_cmd	*holder_nodes;
	int		iterate;
	int		iterate_for_fds;
	int		*pids;
	int		it_it_fds[2];

	holder_nodes = cmd;
	pids = malloc(sizeof(int) * original_cmds);
	iterate = 0;
	iterate_for_fds = 0;
	while (iterate < original_cmds && (holder_nodes))
	{
		holder_nodes->size_of_list = original_cmds;
		it_it_fds[0] = iterate;
		it_it_fds[1] = iterate_for_fds;
		pids[iterate] = fork();
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		if (pids[iterate] == 0)
			help_for_execute_commands(holder_nodes, env_var, pipes, it_it_fds);
		iterate_func(&iterate, &iterate_for_fds, &holder_nodes);
	}
	free(pids);
	return (0);
}

int	execute_command(t_cmd *cmd, t_env **env_var)
{
	int	pid;

	pid = 0;
	signal(SIGINT, handler_two);
	signal(SIGQUIT, handler_two);
	if (cmd->cmd_w_arg != NULL)
		handle_q_mark(cmd);
	if (cmd->cmd_w_arg != NULL && is_there_a_built_in(cmd))
		return (func_red_execut_command(cmd, env_var));
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (access(cmd->cmd_w_arg[0], X_OK) == -1
				&& ft_error(cmd, (*env_var)))
				exit(g_exit_status);
			execute_command_helper_main(cmd, env_var);
			exit (0);
		}
	}
	wait_stat(pid);
	return (0);
}
