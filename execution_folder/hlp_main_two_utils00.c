/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hlp_main_two_utils00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:06:55 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 23:19:45 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	hlp_main_two_built_in(t_cmd *holder_nodes, t_env **env_var, int *pipes)
{
	if (is_there_a_built_in(holder_nodes))
	{
		help_main_two_built_in_separ_one(holder_nodes, env_var);
	}
	if (holder_nodes->out_file_op > 1)
	{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	if (holder_nodes->in_file_op > -1)
	{
		execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	else
	{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
	}
}

void	separ_ft_pwd_help_main_two_two_bt(t_cmd *holder_nodes)
{
	ft_pwd(holder_nodes, holder_nodes->out_file_op);
	exit (0);
}

void	separ_hlp_main_two_bl_in_two(t_cmd *holder_nodes,
	t_env **env_var)
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
		separ_ft_pwd_help_main_two_two_bt(holder_nodes);
	else if (ft_strcmp(which_built_in(holder_nodes), "unset") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "exit") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "env") == 0)
	{
		env_show(holder_nodes, env_var, holder_nodes->out_file_op);
		exit (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "echo") == 0)
	{
		ft_echo(holder_nodes, holder_nodes->out_file_op);
		exit (0);
	}
}

void	hlp_main_two_built_in_two(t_cmd *holder_nodes,
	t_env **env_var, int *pipes, int iterate_for_fds)
{
	if (is_there_a_built_in(holder_nodes))
	{
		separ_hlp_main_two_bl_in_two(holder_nodes,
			env_var);
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
