/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hlp_main_two_utils_01.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:24:01 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 23:16:38 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	spera_ft_pwd_hlp_mn_two_one(t_cmd *holder_nodes)
{
	ft_pwd(holder_nodes, holder_nodes->out_file_op);
	exit (0);
}

void	help_main_two_built_in_separ_one(t_cmd *holder_nodes,
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
		spera_ft_pwd_hlp_mn_two_one(holder_nodes);
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
