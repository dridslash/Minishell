/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:10:22 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 10:37:50 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

char	*get_curr_dir(void)
{
	char	current_dir[FILE_N_MAX];
	char	*dir;

	current_dir[FILE_N_MAX - 1] = '\0';
	getcwd(current_dir, FILE_N_MAX);
	dir = current_dir;
	return (dir);
}

int	is_slash(char *string)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == '/')
			return (1);
	}
	return (0);
}

int	ft_error(t_cmd *cmd, t_env *env_var)
{
	char	*tmp;

	tmp = get_path(cmd->cmd_w_arg[0], env_var);
	if (cmd->cmd_w_arg != NULL)
	{
		if (ft_strcmp(cmd->cmd_w_arg[0], "") == 0)
		{
			free(tmp);
			return (ft_error_for_qt(cmd));
		}
		if ((is_slash(cmd->cmd_w_arg[0]) && access(tmp, F_OK) == -1))
			return (ft_error_for_dir(cmd, &tmp));
		else if (access(tmp, X_OK) == -1
			&& (ft_strcmp(cmd->cmd_w_arg[0], "cd") != 0
				&& ft_strcmp(cmd->cmd_w_arg[0], "export") != 0
				&& ft_strcmp(cmd->cmd_w_arg[0], "pwd") != 0
				&& ft_strcmp(cmd->cmd_w_arg[0], "unset") != 0
				&& ft_strcmp(cmd->cmd_w_arg[0], "echo") != 0
				&& ft_strcmp(cmd->cmd_w_arg[0], "exit") != 0
				&& ft_strcmp(cmd->cmd_w_arg[0], "env") != 0))
			return (ft_error_for_ex(cmd, env_var, &tmp));
	}
	free(tmp);
	return (0);
}
