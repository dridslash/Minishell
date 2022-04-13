/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_part_two_of_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:06:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 21:53:32 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	free_bi_iterate(char **tmp, char **tmp2, t_env **iterta)
{
		(*iterta) = (*iterta)->next_env;
	free(*tmp);
	free(*tmp2);
}

void	ft_pt_two_helper(t_cmd *cmd, t_env **env_var, int index, int *found)
{
	t_env	*iterta;
	char	*tmp;
	char	*tmp2;
	char	*tp;

	iterta = (*env_var);
	while (iterta)
	{
		tmp = get_name_of_env_var(iterta->path_env);
		tmp2 = get_name_of_env_var(cmd->cmd_w_arg[index + 1]);
		if (ft_strcmp(tmp, tmp2) == 0)
		{
			free(tmp);
			free(tmp2);
			tp = iterta->path_env;
			tmp = get_after_equal(cmd->cmd_w_arg[index + 1]);
			iterta->path_env = ft_strjoin_non_free(iterta->path_env, tmp);
			free(tp);
			free(tmp);
			(*found) = 0;
			break ;
		}
		free_bi_iterate(&tmp, &tmp2, &iterta);
	}
}

void	ft_pt_two_helper_two(t_cmd *cmd, t_env **env_var, int index, char **tmp)
{
	char	*value_dollar;
	char	**helpp_plus;
	char	**big_boy;
	char	*tmp3;

	tmp3 = get_after_dollar(cmd->cmd_w_arg[index + 1]);
	value_dollar = search_in_env(env_var, tmp3);
	if (tmp3)
		free(tmp3);
	big_boy = ft_split_execution(cmd->cmd_w_arg[index + 1], '$');
	(*tmp) = big_boy[0];
	big_boy[0] = ft_strjoin(big_boy[0], value_dollar);
	free(*tmp);
	helpp_plus = ft_split_execution(big_boy[0], '+');
	(*tmp) = big_boy[0];
	big_boy[0] = ft_strjoin_non_free(helpp_plus[0], helpp_plus[1]);
	free(*tmp);
	create_env(env_var, big_boy[0]);
	free(value_dollar);
	free_split_in(big_boy);
	free_split_in(helpp_plus);
}

void	part_of_help(t_cmd *cmd, int index, char **tmp, t_env **env_var)
{
	char	*joined;
	char	*tmp2;

	joined = get_name_of_env_var(cmd->cmd_w_arg[index + 1]);
	(*tmp) = joined;
	joined = ft_strjoin_non_free((*tmp), "=");
	free(*tmp);
	(*tmp) = joined;
	tmp2 = get_after_equal(cmd->cmd_w_arg[index + 1]);
	joined = ft_strjoin_non_free(joined, tmp2);
	free(tmp2);
	free(*tmp);
	create_env(env_var, joined);
	if (joined)
		free(joined);
}

int	part_two_of_export(t_cmd *cmd, t_env **env_var)
{
	int		index;
	int		found;
	char	*tmp;

	index = 0;
	found = 1;
	ft_pt_two_helper(cmd, env_var, index, &found);
	if (found == 1)
	{
		if (check_is_dollar_after_equal(cmd) == 1)
			ft_pt_two_helper_two(cmd, env_var, index, &tmp);
		else
			part_of_help(cmd, index, &tmp, env_var);
	}
	return (1);
}
