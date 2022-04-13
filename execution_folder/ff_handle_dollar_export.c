/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_handle_dollar_export.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:16:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 10:54:36 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	part_one_of_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*value_dollar;
	char	*tmp;

	tmp = get_after_dollar(cmd->cmd_w_arg[index + 1]);
	value_dollar = search_in_env(env_var, tmp);
	free(tmp);
	big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
	tmp = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
	create_env(env_var, big_boy[0]);
	free(tmp);
	free_split_in(big_boy);
	free(value_dollar);
}

void	part_two_of_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*value_dollar;
	char	*tmp;
	char	*tmp2;

	tmp = get_after_dollar(cmd->cmd_w_arg[index + 1]);
	value_dollar = search_in_env(env_var, tmp);
	free(tmp);
	big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
	tmp = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
	free(tmp);
	tmp = big_boy[0];
	tmp2 = ft_itoa(g_exit_status);
	big_boy[0] = ft_strjoin(big_boy[0], tmp2);
	free(tmp);
	free(tmp2);
	create_env(env_var, big_boy[0]);
	free_split_in(big_boy);
	free(value_dollar);
}

void	part_three_of_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*value_dollar;
	char	*tmp;
	char	*tmp3;

	tmp = get_after_dollar(cmd->cmd_w_arg[index + 1]);
	value_dollar = search_in_env(env_var, tmp);
	free(tmp);
	big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
	tmp = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
	free(tmp);
	tmp = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], "=");
	free(tmp);
	tmp = big_boy[0];
	tmp3 = get_after_equal(cmd->cmd_w_arg[index + 1]);
	big_boy[0] = ft_strjoin(big_boy[0], tmp3);
	free(tmp);
	free(tmp3);
	create_env(env_var, big_boy[0]);
	free(value_dollar);
	free_split_in(big_boy);
}

void	handle_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*tmp2;
	char	*tmp3;

	tmp2 = get_after_dollar(cmd->cmd_w_arg[index + 1]);
	tmp3 = search_in_env(env_var, tmp2);
	if (tmp3 == NULL)
		write(2, "export Error\n", 13);
	else if (check_is_dollar_after_equal(cmd) && check_exit_status(cmd) == 0)
		part_one_of_dollar_helper(cmd, env_var, index, big_boy);
	else if (check_exit_status(cmd))
		part_two_of_dollar_helper(cmd, env_var, index, big_boy);
	else
	{
		part_three_of_dollar_helper(cmd, env_var, index, big_boy);
	}
	if (tmp2)
		free(tmp2);
	if (tmp3)
		free(tmp3);
}

int	handle_dollar_export(t_cmd *cmd, t_env **env_var)
{
	int		i;
	int		index;
	int		locker;
	char	**big_boy;

	big_boy = NULL;
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
