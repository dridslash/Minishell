/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:09:45 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 16:14:43 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_echo_helper_main(t_cmd *cmd,
	int args, int option_of_echo, int index_tmp)
{
	if (ft_strcmp(cmd->cmd_w_arg[option_of_echo], "-n") != 0)
	{
		sub_echo_helper(cmd, args, option_of_echo, index_tmp);
	}
	else
	{
		sub_echo_helper_two(cmd, args, option_of_echo, index_tmp);
	}
}

void	ft_echo(t_cmd *cmd)
{
	int	index_tmp;
	int	option_of_echo;
	int	args;

	index_tmp = 0;
	args = 0;
	option_of_echo = index_tmp + 1;
	if (cmd->cmd_w_arg[index_tmp] != NULL
		&& (ft_strcmp(cmd->cmd_w_arg[index_tmp], "echo") == 0))
	{
		if (minus_ns(cmd, index_tmp + 1) == how_many_args(cmd, index_tmp + 1))
		{
			write(1, "", 1);
			return ;
		}
		if (cmd->cmd_w_arg[option_of_echo] != NULL)
		{
			ft_echo_helper_main(cmd, args, option_of_echo, index_tmp);
		}
		else
		{
			write(1, "\n", 1);
		}
	}
}
