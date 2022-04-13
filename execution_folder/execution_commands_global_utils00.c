/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_commands_global_utils00.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:49:46 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 18:57:00 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	func_built_ins_send_redi_two(t_cmd *holder_nodes,
	int *pipes, int iterate_for_fds, t_env **env_var)
{
	if (is_there_a_built_in(holder_nodes))
	{
		help_func_send_redi_two(holder_nodes, env_var);
	}
	if (holder_nodes->out_file_op > 1)
	{
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	if (holder_nodes->in_file_op > 0)
	{
		execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	else
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
}

void	help_send_redi_three(t_cmd *holder_nodes,
		int *pipes, int iterate_for_fds, t_env **env_var)
{
	if (ft_strcmp(which_built_in(holder_nodes), "cd") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "export") == 0)
	{
		ft_export_send_redi_three_hlp(holder_nodes,
			pipes, iterate_for_fds, env_var);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "pwd") == 0
		&& (get_index_of_env_var(env_var, "PATH") == -1))
	{
		ft_pwd(holder_nodes, pipes[iterate_for_fds + 1]);
		exit (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "unset") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "exit") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "env") == 0)
	{
		env_show_send_redi_three_hlp(holder_nodes,
			pipes, iterate_for_fds, env_var);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "echo") == 0)
		ft_echo_send_redi_three_hlp(holder_nodes,
			pipes, iterate_for_fds);
}

void	func_built_ins_send_redi_three(t_cmd *holder_nodes,
	int *pipes, int iterate_for_fds, t_env **env_var)
{
	if (is_there_a_built_in(holder_nodes))
	{
		help_send_redi_three(holder_nodes, pipes, iterate_for_fds, env_var);
	}
	if (holder_nodes->out_file_op > 1)
	{
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	else if (holder_nodes->in_file_op > 0)
	{
		execute_cmds_close_files(holder_nodes->in_file_op,
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	else
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
}

void	handler_two(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_exit_status = 1;
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 0;
	}
}
