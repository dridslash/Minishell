/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:03:14 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 17:41:56 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_pwd(t_cmd *cmd, t_env *env_var)
{
	char	current_dir[FILE_N_MAX];

	if ((cmd->cmd_w_arg[0] != NULL)
		&& ((ft_strcmp(cmd->cmd_w_arg[0], "pwd") == 0)
			|| (ft_strcmp(cmd->cmd_w_arg[0], "PWD") == 0)))
	{
		current_dir[FILE_N_MAX - 1] = '\0';
		getcwd(current_dir, FILE_N_MAX);
		printf("%s\n", current_dir);
	}
}
