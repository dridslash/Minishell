/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manage_ut00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:58:51 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 18:39:53 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	ft_error_for_qt(t_cmd *cmd)
{
	write(2, ":", 10);
	write(2, cmd->cmd_w_arg[0], ft_strlen(cmd->cmd_w_arg[0]));
	write(2, ":", 1);
	g_exit_status = 127;
	write(2, "command not found\n", 18);
	return (1);
}

int	ft_error_for_dir(t_cmd *cmd, char **tmp)
{
	write(2, cmd->cmd_w_arg[0], ft_strlen(cmd->cmd_w_arg[0]));
	write(2, ":", 1);
	write(2, "No such file or directory\n", 26);
	free(*tmp);
	g_exit_status = 127;
	return (1);
}

int	ft_error_for_ex(t_cmd *cmd, t_env *env_var, char **tmp)
{
	if (get_index_of_env_var(&env_var, "PATH") == -1)
	{
		write(2, cmd->cmd_w_arg[0], ft_strlen(cmd->cmd_w_arg[0]));
		write(2, ":", 1);
		write(2, " No such file or directory\n", 27);
		free(*tmp);
		g_exit_status = 127;
		return (1);
	}
	else
	{
		write(2, cmd->cmd_w_arg[0], ft_strlen(cmd->cmd_w_arg[0]));
		write(2, ":", 1);
		write(2, " command not found\n", 19);
		free(*tmp);
		g_exit_status = 127;
		return (1);
	}
	return (0);
}
