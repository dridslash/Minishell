/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_part_two_of_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:06:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/08 19:53:59 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_pt_two_helper(t_cmd *cmd, t_env **env_var, int index, int *found)
{
	t_env	*iterta;
	char	*expand_dollar;

	iterta = (*env_var);
	while (iterta)
	{
		if (ft_strcmp(get_name_of_env_var(iterta->path_env),
				get_name_of_env_var(cmd->cmd_w_arg[index + 1])) == 0)
		{
			iterta->path_env = ft_strjoin_non_free(iterta->path_env,
					get_after_equal(cmd->cmd_w_arg[index + 1]));
			(*found) = 0;
			break ;
		}
		iterta = iterta->next_env;
	}
}

int	part_two_of_export(t_cmd *cmd, t_env **env_var)
{
	char	**helpp_plus;
	int		index;
	char	*joined;
	int		found;
	char	*value_dollar;
	char	**big_boy;

	index = 0;
	found = 1;
	ft_pt_two_helper(cmd, env_var, index, &found);
	if (found == 1)
	{
		if (check_is_dollar_after_equal(cmd) == 1)
		{
			value_dollar = search_in_env(env_var,
				get_after_dollar(cmd->cmd_w_arg[index + 1]));
			big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
			big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
			helpp_plus = ft_split_execution(big_boy[0], '+');
			big_boy[0] = helpp_plus[0];
			big_boy[0] = ft_strjoin_non_free(big_boy[0],helpp_plus[1]);
		create_env(env_var, big_boy[0]);
		}
		else
		{
		joined = get_name_of_env_var(cmd->cmd_w_arg[index + 1]);
		joined = ft_strjoin_non_free(joined, "=");
		joined = ft_strjoin_non_free(joined,
				get_after_equal(cmd->cmd_w_arg[index + 1]));
		create_env(env_var, joined);
		}
		return (1);
	}
	return (1);
}
