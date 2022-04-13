/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separ_help_of_help_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:51:51 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 23:14:27 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	separ_ft_pwd_help_of_help_two_built_in_two(t_cmd *holder_nodes,
	int iterate_for_fds, int *pipes)
{
	if (holder_nodes->out_file_op > 1)
		ft_pwd(holder_nodes, holder_nodes->out_file_op);
	else
		ft_pwd(holder_nodes, pipes[iterate_for_fds + 1]);
	exit (0);
}

void	separ_ft_export_help_of_help_two_built_in_two(t_cmd *holder_nodes,
	int iterate_for_fds, int *pipes, t_env **env_var)
{
	if (holder_nodes->out_file_op > 1)
		ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
	else
		ft_export_var(holder_nodes, env_var, pipes[iterate_for_fds + 1]);
	exit (0);
}

void	separ_ft_echo_help_of_help_two_built_in_two(t_cmd *holder_nodes,
	int iterate_for_fds, int *pipes)
{
	if (holder_nodes->out_file_op > 1)
		ft_echo(holder_nodes, holder_nodes->out_file_op);
	else
		ft_echo(holder_nodes, pipes[iterate_for_fds + 1]);
	exit (0);
}
