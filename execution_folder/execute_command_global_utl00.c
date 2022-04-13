/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_global_utl00.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:11:56 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 13:16:27 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	help_func_pwd_command_help(t_cmd *cmd)
{
	ft_pwd(cmd, cmd->out_file_op);
	write(cmd->out_file_op, "\n", 1);
	return (0);
}

int	help_func_cd_command_help(t_cmd *cmd)
{
	ft_cd(cmd);
	return (0);
}

int	func_red_execut_command(t_cmd *cmd, t_env **env_var)
{
	if (ft_strcmp(which_built_in(cmd), "cd") == 0)
		return (help_func_cd_command_help(cmd));
	else if (ft_strcmp(which_built_in(cmd), "export") == 0)
	{
		ft_export_var(cmd, env_var, cmd->out_file_op);
		return (0);
	}
	else if (ft_strcmp(which_built_in(cmd), "pwd") == 0)
		return (help_func_pwd_command_help(cmd));
	else if (ft_strcmp(which_built_in(cmd), "unset") == 0)
	{
		ft_unset(env_var, cmd);
		return (0);
	}
	else if (ft_strcmp(which_built_in(cmd), "env") == 0)
	{
		env_show(cmd, env_var, 1);
		return (0);
	}
	if (ft_strcmp(which_built_in(cmd), "echo") == 0)
	{
		ft_echo(cmd, cmd->out_file_op);
		return (0);
	}
	return (0);
}

void	wait_stat(int pid)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED (status))
		g_exit_status = WEXITSTATUS(status);
}

void	execute_command_helper_main(t_cmd *cmd, t_env **env_var)
{
	if (cmd->out_file_op == -100
		|| cmd->in_file_op == -100 || cmd->cmd_w_arg == NULL)
		exit (1);
	dup2(cmd->in_file_op, 0);
	dup2(cmd->out_file_op, 1);
	execve(get_path(cmd->cmd_w_arg[0],
			(*env_var)), cmd->cmd_w_arg, fill_envp((*env_var)));
}
