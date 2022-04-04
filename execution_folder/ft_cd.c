/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:31:07 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/03 17:44:02 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_cd_helper(t_cmd *cmd, int index, char *get_home)
{
	if (ft_strcmp(cmd->cmd_w_arg[0], "cd") == 0)
	{
		if (cmd->cmd_w_arg[index + 1] != NULL)
		{
			if (ft_strcmp(cmd->cmd_w_arg[index + 1], "~") == 0)
			{
				if (chdir(get_home))
					perror(">>shell : cd ");
			}
			else
			{
				if (chdir(cmd->cmd_w_arg[index + 1]) != 0)
					perror(">>shell : cd ");
			}
		}
		else
			chdir(get_home);
	}
	else
	{
		if (chdir(cmd->cmd_w_arg[0]) != 0)
			perror(">>shell : cd ");
	}
}

void	ft_cd(t_cmd *cmd, t_env *env_var)
{
	char	current_dir[FILE_N_MAX];
	char	*get_home;
	int		index;

	index = 0;
	get_home = getenv("HOME");
	current_dir[FILE_N_MAX - 1] = '\0';
	getcwd(current_dir, FILE_N_MAX);
	ft_cd_helper(cmd, index, get_home);
}
