/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_part_two_of_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:06:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 15:35:13 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	ft_pt_two_helper(t_cmd *cmd, t_env **env_var, int index, int *found)
{
	t_env	*iterta;

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
	int		i;
	int		index;
	char	*joined;
	int		found;

	i = 0;
	index = 0;
	found = 1;
	ft_pt_two_helper(cmd, env_var, index, &found);
	if (found == 1)
	{
		joined = get_name_of_env_var(cmd->cmd_w_arg[index + 1]);
		joined = ft_strjoin_non_free(joined, "=");
		joined = ft_strjoin_non_free(joined,
				get_after_equal(cmd->cmd_w_arg[index + 1]));
		create_env(env_var, joined);
		return (1);
	}
	return (1);
}
