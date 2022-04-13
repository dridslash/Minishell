/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_help_of_help_ut01.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:06:08 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 10:36:41 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	pwd_separ_built_in_red_two(t_cmd *holder_nodes)
{
	ft_pwd(holder_nodes, holder_nodes->out_file_op);
	write(holder_nodes->out_file_op, "\n", 1);
	return (0);
}

int	ft_cd_separ_built_in_red_two(t_cmd *holder_nodes)
{
	ft_cd(holder_nodes);
	return (0);
}

int	ft_echo_separ_buint_in_red_two(t_cmd *holder_nodes)
{
	ft_echo(holder_nodes, holder_nodes->out_file_op);
	return (0);
}

int	separ_help_help_built_in_red_two(t_cmd *holder_nodes,
	t_env **env_var)
{
	if (ft_strcmp(which_built_in(holder_nodes), "cd") == 0)
		return (ft_cd_separ_built_in_red_two(holder_nodes));
	else if (ft_strcmp(which_built_in(holder_nodes), "export") == 0)
	{
		ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
		return (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "pwd") == 0
		&& (get_index_of_env_var(env_var, "PATH") == -1))
		return (pwd_separ_built_in_red_two(holder_nodes));
	else if (ft_strcmp(which_built_in(holder_nodes), "unset") == 0)
	{
		ft_unset(env_var, holder_nodes);
		return (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "env") == 0)
	{
		env_show(holder_nodes, env_var, 1);
		return (0);
	}
	else if (ft_strcmp(which_built_in(holder_nodes), "echo") == 0)
		return (ft_echo_separ_buint_in_red_two(holder_nodes));
	return (0);
}
