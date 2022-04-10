/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_handle_dollar_export.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:16:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/10 12:22:28 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

char	*search_in_env(t_env **envv, char *your_var)
{
	t_env	*aff;
	char	*tmp;
	char	*tmp2;

	aff = (*envv);
	while (aff)
	{
		tmp = get_name_of_env_var(aff->path_env);
		tmp2 = get_name_of_env_var(your_var);
		if (ft_strcmp(tmp,
				tmp2) == 0)
		{
			free(tmp);
			free(tmp2);
			return (get_after_equal(aff->path_env));
		}
		aff = aff->next_env;
		free(tmp);
		free(tmp2);
	}
	return (ft_strdup_execution(""));
}

int check_exit_status(t_cmd *cmd)
{
	int index_tmp;
	int i;

	index_tmp = 0;
	i = 0;
	char *holder = cmd->cmd_w_arg[index_tmp + 1];
	if (check_if_there_is_a_dollar(cmd->cmd_w_arg[index_tmp + 1]) == 1)
	{
		while(holder[i])
		{
			if ((holder[i] == '$' && holder[i + 1] == '?') && i > get_equal_index(holder))
				return(1);
				i++;
		}
	}
	return (0);
}

int check_is_dollar_after_equal(t_cmd *cmd)
{
	int index_tmp;
	int i;

	index_tmp = 0;
	i = 0;
	char *holder = cmd->cmd_w_arg[index_tmp + 1];
	if (check_if_there_is_a_dollar(cmd->cmd_w_arg[index_tmp + 1]) == 1)
	{
		while(holder[i])
		{
			if (holder[i] == '$' && i > get_equal_index(holder))
				return(1);
				i++;
		}
	}
	return (0);
}

void	handle_dollar_helper(t_cmd *cmd, t_env **env_var,
	int index, char **big_boy)
{
	char	*value_dollar;
	char	*test;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (search_in_env(env_var,
			get_after_dollar(cmd->cmd_w_arg[index + 1])) == NULL)
	{
		write(2, "export Error\n", 13);
	}
	else if (check_is_dollar_after_equal(cmd) && check_exit_status(cmd) == 0)
	{
		value_dollar = search_in_env(env_var,
				get_after_dollar(cmd->cmd_w_arg[index + 1]));
			big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
			tmp = big_boy[0];
			big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
		create_env(env_var, big_boy[0]);
		free_split_in(big_boy);
		free(tmp);
	}
	else if (check_exit_status(cmd))
	{
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
		free(tmp);
		free(tmp2);
	}
	else
	{
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
		free_split_in(big_boy);
		free(tmp);
		free(tmp2);
		free(tmp3);
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
