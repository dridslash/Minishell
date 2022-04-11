/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_handle_dollar_export.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:16:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/11 13:45:08 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	part_one_of_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*value_dollar;
	char	*tmp;

	value_dollar = search_in_env(env_var,
			get_after_dollar(cmd->cmd_w_arg[index + 1]));
	big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
	tmp = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
	create_env(env_var, big_boy[0]);
	free_split_in(big_boy);
		//free(tmp);
}

void	part_two_of_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*value_dollar;
	char	*tmp;
	char	*tmp2;

	value_dollar = search_in_env(env_var,
			get_after_dollar(cmd->cmd_w_arg[index + 1]));
	big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
	tmp = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
	tmp2 = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0],
			ft_itoa(exit_status));
	create_env(env_var, big_boy[0]);
	free_split_in(big_boy);
		//free(tmp);
		//free(tmp2);
}

void	part_three_of_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*value_dollar;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	value_dollar = search_in_env(env_var,
			get_after_dollar(cmd->cmd_w_arg[index + 1]));
	big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
	tmp = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
	tmp2 = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], "=");
	tmp3 = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0],
			get_after_equal(cmd->cmd_w_arg[index + 1]));
	create_env(env_var, big_boy[0]);
		//free_split_in(big_boy);
		//free(tmp);
		//free(tmp2);
		//free(tmp3);
}

void	handle_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*test;
	char	*tmp2;
	char	*tmp3;

	if (search_in_env(env_var,
			get_after_dollar(cmd->cmd_w_arg[index + 1])) == NULL)
	{
		write(2, "export Error\n", 13);
	}
	else if (check_is_dollar_after_equal(cmd) && check_exit_status(cmd) == 0)
		part_one_of_dollar_helper(cmd, env_var, index, big_boy);
	else if (check_exit_status(cmd))
		part_two_of_dollar_helper(cmd, env_var, index, big_boy);
	else
	{
		part_three_of_dollar_helper(cmd, env_var, index, big_boy);
	}
}

int	handle_dollar_export(t_cmd *cmd, t_env **env_var)
{
	int		i;
	int		index;
	int		locker;
	char	**big_boy;

	locker = 0;
	index = 0;
	i = 0;
	if (cmd->cmd_w_arg[index + 1] != NULL
		&& get_equal_index(cmd->cmd_w_arg[index + 1]) != -1)
	{
		handle_dollar_helper(cmd, env_var, index, big_boy);
	}
	return (1);
}
