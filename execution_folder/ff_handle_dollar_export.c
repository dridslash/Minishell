/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_handle_dollar_export.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:16:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/08 14:01:47 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

char	*search_in_env(t_env **envv, char *your_var)
{
	t_env	*aff;

	aff = (*envv);
	while (aff)
	{
		if (ft_strcmp(get_name_of_env_var(aff->path_env),
				get_name_of_env_var(your_var)) == 0)
		{
			return (get_after_equal(aff->path_env));
		}
		aff = aff->next_env;
	}
	return (ft_strdup_execution(""));
}

void	handle_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*value_dollar;

	if (search_in_env(env_var,
			get_after_dollar(cmd->cmd_w_arg[index + 1])) == NULL)
	{
		write(2, "export Error\n", 13);
	}
	else
	{
			value_dollar = search_in_env(env_var,
				get_after_dollar(cmd->cmd_w_arg[index + 1]));
			big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
			big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
			big_boy[0] = ft_strjoin(big_boy[0], "=");
			big_boy[0] = ft_strjoin(big_boy[0],
				get_after_equal(cmd->cmd_w_arg[index + 1]));
		create_env(env_var, big_boy[0]);
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
