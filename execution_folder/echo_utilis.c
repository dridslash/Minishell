/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:05:49 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 11:53:33 by mnaqqad          ###   ########.fr       */
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

void	sub_echo_helper(t_cmd *cmd, int args, int option_of_echo, int out_file)
{
	if (charachter_eater(cmd, 0, option_of_echo) > 0)
	{
		args = option_of_echo;
		while (cmd->cmd_w_arg[args])
		{
			if (ft_strcmp(cmd->cmd_w_arg[args], "") == 0)
			{
				write(out_file, " ", 1);
			}
			write(out_file, cmd->cmd_w_arg[args], strlen(cmd->cmd_w_arg[args]));
			if (cmd->cmd_w_arg[args + 1])
				write(out_file, " ", 1);
			args++;
		}
		write(out_file, "\n", 1);
	}
	else
	{
		write(out_file, " \n", 2);
	}
}

void	sub_echo_helper_two(t_cmd *cmd,
	int args, int option_of_echo, int out_file)
{
	int	index_tmp;

	index_tmp = 0;
	if (charachter_eater(cmd, 1, option_of_echo) > 0)
	{
		if (minus_ns(cmd, index_tmp + 1) == how_many_args(cmd, index_tmp + 1))
		{
			write(out_file, "", 0);
			return ;
		}
		args = option_of_echo + 1;
		while (cmd->cmd_w_arg[args])
		{
			if (ft_strcmp(cmd->cmd_w_arg[args], "") == 0)
			{
				write(out_file, " ", 1);
			}
			write(out_file, cmd->cmd_w_arg[args], strlen(cmd->cmd_w_arg[args]));
			if (cmd->cmd_w_arg[args + 1])
				write(out_file, " ", 1);
			args++;
		}
	}
}
