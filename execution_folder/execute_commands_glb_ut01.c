/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands_glb_ut01.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:12:36 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 22:29:03 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	help_func_send_redi(t_cmd *holder_nodes,
			int *pipes, int iterate_for_fds, t_env **env_var)
{
	if (ft_strcmp(which_built_in(holder_nodes), "cd") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "export") == 0)
		ft_export_separat_send_redi(holder_nodes, pipes,
			iterate_for_fds, env_var);
	else if (ft_strcmp(which_built_in(holder_nodes), "pwd") == 0
		&& (get_index_of_env_var(env_var, "PATH") == -1))
	{
		ft_pwd_separat_send_redi(holder_nodes, pipes, iterate_for_fds);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "unset") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "exit") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "env") == 0)
	{
		if (holder_nodes->out_file_op > 1)
			env_show(holder_nodes, env_var, holder_nodes->out_file_op);
		else
			env_show(holder_nodes, env_var, pipes[iterate_for_fds + 1]);
		exit (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "echo") == 0)
		ft_echo_separat_send_redi(holder_nodes,
			pipes, iterate_for_fds);
}

void	func_built_ins_send_redi(t_cmd *holder_nodes,
	int *pipes, int iterate_for_fds, t_env **env_var)
{
	if (is_there_a_built_in(holder_nodes))
	{
		help_func_send_redi(holder_nodes, pipes, iterate_for_fds, env_var);
	}
	if (holder_nodes->out_file_op > 1)
	{
		execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	else
		execute_cmds_close_files(holder_nodes->in_file_op,
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
}

void	separat_send_redi_two(t_cmd *holder_nodes)
{
	ft_echo(holder_nodes, holder_nodes->out_file_op);
	exit (0);
}

void	help_func_send_redi_two(t_cmd *holder_nodes, t_env **env_var)
{
	if (ft_strcmp(which_built_in(holder_nodes), "cd") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "export") == 0)
	{
		ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
		exit (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "pwd") == 0
		&& (get_index_of_env_var(env_var, "PATH") == -1))
	{
		ft_pwd(holder_nodes, holder_nodes->out_file_op);
		exit (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "unset") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "exit") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "env") == 0)
	{
		env_show(holder_nodes, env_var, 1);
		exit (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "echo") == 0)
		separat_send_redi_two(holder_nodes);
}
