/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:31:07 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 10:51:04 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_cd_helper_of_helper(t_cmd *cmd,
	int index, char *get_home, char **path)
{
	path = ft_split_execution(cmd->cmd_w_arg[index + 1], '~');
	if (chdir(get_home) != 0)
		perror("cd ");
	if (chdir(&path[0][1]) != 0)
		perror("cd ");
	free_split_in(path);
}

void	ft_cd_helper(t_cmd *cmd, int index, char *get_home)
{
	char	**path;

	path = NULL;
	if (ft_strcmp(cmd->cmd_w_arg[0], "cd") == 0)
	{
		if (cmd->cmd_w_arg[index + 1] != NULL)
		{
			if (ft_strcmp(cmd->cmd_w_arg[index + 1], "~") == 0)
			{
				if (chdir(get_home) != 0)
					perror("cd ");
			}
			else if (cmd->cmd_w_arg[index + 1][0] == '~')
			{
				ft_cd_helper_of_helper(cmd, index, get_home, path);
			}
			else
			{
				if (chdir(cmd->cmd_w_arg[index + 1]) != 0)
					perror("cd ");
			}
		}
		else
			chdir(get_home);
	}
}

void	ft_cd(t_cmd *cmd)
{
	char	current_dir[FILE_N_MAX];
	char	*get_home;
	int		index;

	index = 0;
	get_home = getenv("HOME");
	current_dir[FILE_N_MAX - 1] = '\0';
	getcwd(current_dir, FILE_N_MAX);
	ft_cd_helper(cmd, index, get_home);
	g_exit_status = 0;
}
