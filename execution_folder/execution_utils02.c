/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:30:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 23:23:46 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	execution_help_of_hlp(t_cmd *holder_nodes, int *pipes, t_env **env_var)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		ft_error(holder_nodes, (*env_var));
		help_of_help_built_in_red_one(holder_nodes, env_var, pipes);
	}
	else
	{
		ft_error(holder_nodes, (*env_var));
		return (help_of_help_built_in_red_two(holder_nodes, env_var, pipes));
	}
	return (0);
}

void	execution_help_of_hlp_two(t_cmd *holder_nodes,
int *it_it_fds, int *pipes, t_env **env_var)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		ft_error(holder_nodes, (*env_var));
		help_of_help_two_built_in_one(holder_nodes,
			it_it_fds[1], pipes, env_var);
	}
	else
	{
		ft_error(holder_nodes, (*env_var));
		help_of_help_two_built_in_two(holder_nodes,
			it_it_fds[1], pipes, env_var);
	}
}

void	execution_hlp_main_one(t_cmd *holder_nodes,
int *it_it_fds, int *pipes, t_env **env_var)
{
	if (it_it_fds[0] + 1 == holder_nodes->size_of_list)
	{
		execution_help_of_hlp(holder_nodes, pipes, env_var);
	}
	else
	{
		execution_help_of_hlp_two(holder_nodes,
			it_it_fds, pipes, env_var);
	}
}

void	execution_hlp_main_two(t_cmd *holder_nodes,
int *it_it_fds, int *pipes, t_env **env_var)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		ft_error(holder_nodes, (*env_var));
		hlp_main_two_built_in(holder_nodes, env_var, pipes);
	}
	else
	{
		ft_error(holder_nodes, (*env_var));
		hlp_main_two_built_in_two(holder_nodes,
			env_var, pipes, it_it_fds[1]);
	}
}

void	exectuion_hlp_main_three(t_cmd *holder_nodes,
int *it_it_fds, int *pipes, t_env **env_var)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		ft_error(holder_nodes, (*env_var));
		hlp_main_three_built_in(holder_nodes, pipes, it_it_fds[1], env_var);
	}
	else
	{
		ft_error(holder_nodes, (*env_var));
		hlp_main_three_built_in_two(holder_nodes,
			pipes, it_it_fds[1], env_var);
	}
}
