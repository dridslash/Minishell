/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separ_main_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:04:53 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 23:12:56 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	separ_ft_pwd_hlp_main_three_bt_two(t_cmd *holder_nodes,
	int *pipes, int iterate_for_fds)
{
	if (holder_nodes->out_file_op > 1)
		ft_pwd(holder_nodes, holder_nodes->out_file_op);
	else
		ft_pwd(holder_nodes, pipes[iterate_for_fds + 1]);
	exit (0);
}

void	separ_ft_export_hlp_main_three_bt_two(t_cmd *holder_nodes,
	int *pipes, int iterate_for_fds, t_env **env_var)
{
	if (holder_nodes->out_file_op > 1)
		ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
	else
		ft_export_var(holder_nodes, env_var, pipes[iterate_for_fds + 1]);
	exit (0);
}

void	separ_ft_echo_hlp_main_three_bt_two(t_cmd *holder_nodes,
	int *pipes, int iterate_for_fds)
{
	if (holder_nodes->out_file_op > 1)
		ft_echo(holder_nodes, holder_nodes->out_file_op);
	else
		ft_echo(holder_nodes, pipes[iterate_for_fds + 1]);
	exit (0);
}
