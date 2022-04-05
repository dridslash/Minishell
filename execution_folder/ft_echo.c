/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:09:45 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/05 16:32:49 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int search_for_status(char *cmd_of_arg)
{
	int i = 0;
	char *holder = cmd_of_arg;
	while (holder[i])
	{
		if (holder[i] == '$' && holder[i + 1] == '	')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void echo_status(char **cmd_of_arg, int args)
{
	int is_special = 0;
	char *c = ft_itoa(70);
	char **splited;
	char *holder;
	if (search_for_status((*cmd_of_arg)) == 1)
	{
		splited = ft_split_execution((*cmd_of_arg), '$');
	
	int i =0;
	holder = splited[0];
	while(splited[i])
	{
		if (splited[i][0] == '	')
		{
		holder = ft_strjoin_non_free(holder, ft_itoa(70));
		holder = ft_strjoin_non_free(holder, &splited[i][1]);
		}
		i++;
	}
	(*cmd_of_arg) = holder;
	}
}

void	ft_echo_helper_main(t_cmd *cmd,
	int args, int option_of_echo, int out_file)
{
	if (ft_strcmp(cmd->cmd_w_arg[option_of_echo], "-n") != 0)
	{
		sub_echo_helper(cmd, args, option_of_echo, out_file);
	}
	else
	{
		sub_echo_helper_two(cmd, args, option_of_echo, out_file);
	}
}

void	ft_echo(t_cmd *cmd, int out_file)
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
			write(out_file, "", 1);
			return ;
		}
		if (cmd->cmd_w_arg[option_of_echo] != NULL)
		{
			ft_echo_helper_main(cmd, args, option_of_echo, out_file);
		}
		else
		{
			write(out_file, "\n", 1);
		}
	}
}
