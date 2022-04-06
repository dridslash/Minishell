/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:01:48 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/06 13:39:25 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_exit(t_cmd *cmd)
{
	int	index;
	int	status;

	index = 0;
	status = 0;
	if (cmd->cmd_w_arg[index] != NULL
		&& (ft_strcmp(cmd->cmd_w_arg[index], "exit") == 0))
	{
		if (cmd->cmd_w_arg[index + 1] != NULL)
		{
			status = ft_atoi(cmd->cmd_w_arg[index + 1]);
			write(1, "exit\n", 5);
			exit(status);
		}
		else
		{
			write(1, "exit\n", 5);
			exit(0);
		}
	}
}
