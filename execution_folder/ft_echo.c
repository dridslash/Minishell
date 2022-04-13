/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:09:45 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 11:53:07 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	search_for_status(char *cmd_of_arg)
{
	int		i;
	char	*holder;

	holder = cmd_of_arg;
	i = 0;
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

int	find_tab(char *cmd_of_arg)
{
	int	i;

	i = 0;
	while (cmd_of_arg[i])
	{
		if (cmd_of_arg[i] == '	')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

// 	splited = ft_split_execution((*cmd_of_arg), '$');
	// int i =0;
	// holder = splited[0];
	//  while(splited[i])
	// {
	// 	if (splited[i][0] == '	')
	//  	{
	// 	holder = ft_strjoin_non_free(ft_itoa(exit_status), holder);
	// 	holder = ft_strjoin_non_free(holder, &splited[i][1]);
	//  	}
	//  	i++;
	//  }
// void echo_status(char **cmd_of_arg, int args)
// {
// 	char **splited;
// 	int sp_index = 0;
// 	char *holder = (*cmd_of_arg);
// 	int i = 0;
// 	int index = 0;
// 	int j = 0;
// 	if (search_for_status((*cmd_of_arg)) == 1)
// 	{
// 	splited = ft_split_execution(holder,'$');
// 	while (splited[i])
// 	{
// 		if (find_tab(splited[i]) == 0)
// 		{
// 			splited[i] = ft_strdup_execution(&splited[i][index + 1]);
// 			splited[i] = ft_strjoin(ft_itoa(10),splited[i]);
// 		}
// 		else if (find_tab(splited[i]) == ft_strlen(splited[i]))
// 		{
// 			splited[i] = ft_itoa(10);
// 		}
// 		i++;
// 	}
// 	i = 1;
// 	while(splited[i])
// 	{
// 		if (j != i)
// 		splited[j] = ft_strjoin(splited[j],splited[i]);
// 		i++;
// 	}
// 	 (*cmd_of_arg) = splited[j];
// 	}
// }

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
			write(out_file, "", 0);
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
	g_exit_status = 0;
}
