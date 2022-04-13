/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_help_of_help_two01_ut.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:05:31 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 23:33:30 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	separ_ft_pwd_help_help_two_one(t_cmd *holder_nodes,
	int iterate_for_fds, int *pipes)
{
	if (holder_nodes->out_file_op > 1)
		ft_pwd(holder_nodes, holder_nodes->out_file_op);
	else
		ft_pwd(holder_nodes, pipes[iterate_for_fds + 1]);
	exit (0);
}

void	separ_ft_export_help_help_two_one(t_cmd *holder_nodes,
	int iterate_for_fds, int *pipes, t_env **env_var)
{
	if (holder_nodes->out_file_op > 1)
		ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
	else
		ft_export_var(holder_nodes, env_var, pipes[iterate_for_fds + 1]);
	exit (0);
}

void	separ_ft_echo_help_help_two_one(t_cmd *holder_nodes,
	int iterate_for_fds, int *pipes)
{
	if (holder_nodes->out_file_op > 1)
		ft_echo(holder_nodes, holder_nodes->out_file_op);
	else
		ft_echo(holder_nodes, pipes[iterate_for_fds + 1]);
	exit (0);
}

void	separ_help_of_help_two_one(t_cmd *holder_nodes,
	int iterate_for_fds, int *pipes, t_env **env_var)
{
	if (ft_strcmp(which_built_in(holder_nodes), "cd") == 0)
		exit (0);
	else if (ft_strcmp(which_built_in(holder_nodes), "export") == 0)
		separ_ft_export_help_help_two_one(holder_nodes,
			iterate_for_fds, pipes, env_var);
	else if (ft_strcmp(which_built_in(holder_nodes), "pwd") == 0
		&& (get_index_of_env_var(env_var, "PATH") == -1))
		separ_ft_pwd_help_help_two_one(holder_nodes,
			iterate_for_fds, pipes);
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
		separ_ft_echo_help_help_two_one(holder_nodes,
			iterate_for_fds, pipes);
}
