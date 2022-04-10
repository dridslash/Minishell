/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_part_one_of_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:57:04 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/10 11:13:42 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	export_pt_one_helper(t_cmd *cmd, t_env **env_var, char *holder)
{
	t_env	*aff;
	int		locker;
	char	*tp2;
	char	*tp;
	char	*tp3;

	locker = 0;
	aff = (*env_var);
	while (aff)
	{
		tp = get_name_of_env_var(aff->path_env);
		tp2 = get_name_of_env_var(holder);
		if (ft_strcmp(tp,
				tp2) == 0)
		{
				tp3 = get_name_of_env_var(aff->path_env);
				aff->path_env = ft_strdup_execution(holder);
				free(tp3);
				locker++;
				free(tp2);
			break ;
		}
			free(tp3);
			free(tp);
			aff = aff->next_env;
			free(tp2);
	}
	if (locker == 0)
	{
		create_env(env_var, holder);
	}
}

int	part_one_of_export(t_cmd *cmd, t_env **env_var)
{
	int		i;
	int		index;
	char	*holder;

	index = 0;
	holder = cmd->cmd_w_arg[index + 1];
	i = 0;
	if (cmd->cmd_w_arg[index + 1] != NULL
		&& get_equal_index(cmd->cmd_w_arg[index + 1]) != -1)
	{
		export_pt_one_helper(cmd, env_var, holder);
	}
	return (1);
}
