/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:05:49 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 16:06:12 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	charachter_eater(t_cmd *cmd, int is_there_stopper_newline, int start)
{
	int	i;
	int	count_if_there_an_arg;

	i = start;
	count_if_there_an_arg = 0;
	if (is_there_stopper_newline == 1)
	i++;
	while (cmd->cmd_w_arg[i])
	{
		if (cmd->cmd_w_arg[i] != NULL)
		{
			count_if_there_an_arg++;
		}
		i++;
	}
	return (count_if_there_an_arg);
}

int	minus_ns(t_cmd *cmd, int start)
{
	int	i;
	int	count_ns;

	i = start;
	count_ns = 0;
	while (cmd->cmd_w_arg[i])
	{
		if (ft_strcmp(cmd->cmd_w_arg[i], "-n") == 0)
		{
			count_ns++;
		}
		i++;
	}
	return (count_ns);
}

int	how_many_args(t_cmd *cmd, int start)
{
	int	i;

	i = start;
	while (cmd->cmd_w_arg[i])
	{
		i++;
	}
	return (i);
}

void	sub_echo_helper(t_cmd *cmd, int args, int option_of_echo, int index_tmp)
{
	if (charachter_eater(cmd, 0, option_of_echo) > 0)
	{
		args = option_of_echo;
		while (cmd->cmd_w_arg[args])
		{
			if (ft_strcmp(cmd->cmd_w_arg[args], "") == 0)
			{
				write(1, " ", 1);
			}
			write(1, cmd->cmd_w_arg[args], strlen(cmd->cmd_w_arg[args]));
			write(1, " ", 1);
			args++;
		}
		write(1, "\n", 1);
	}
}

void	sub_echo_helper_two(t_cmd *cmd,
	int args, int option_of_echo, int index_tmp)
{
	if (charachter_eater(cmd, 1, option_of_echo) > 0)
	{
		if (minus_ns(cmd, index_tmp + 1) == how_many_args(cmd, index_tmp + 1))
		{
			write(1, "", 1);
			return ;
		}
		args = option_of_echo + 1;
		while (cmd->cmd_w_arg[args])
		{
			if (ft_strcmp(cmd->cmd_w_arg[args], "") == 0)
			{
				write(1, " ", 1);
			}
			write(1, cmd->cmd_w_arg[args], strlen(cmd->cmd_w_arg[args]));
			args++;
		}
	}
	else
		write(1, "", 1);
}
