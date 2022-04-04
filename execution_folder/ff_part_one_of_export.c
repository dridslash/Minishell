/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_part_one_of_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:57:04 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 15:30:06 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	export_pt_one_helper(t_cmd *cmd, t_env **env_var, char *holder)
{
	t_env	*aff;
	int		locker;

	locker = 0;
	aff = (*env_var);
	while (aff)
	{
		if (ft_strcmp(get_name_of_env_var(aff->path_env),
				get_name_of_env_var(holder)) == 0)
		{
				aff->path_env = holder;
				locker++;
			break ;
		}
			aff = aff->next_env;
	}
	if (locker == 0)
	{
		create_env(env_var, holder);
	}
		aff = (*env_var);
}

int	part_one_of_export(t_cmd *cmd, t_env **env_var)
{
	int		i;
	int		index;
	char	*holder;

	holder = cmd->cmd_w_arg[index + 1];
	index = 0;
	i = 0;
	if (cmd->cmd_w_arg[index + 1] != NULL
		&& get_equal_index(cmd->cmd_w_arg[index + 1]) != -1)
	{
		export_pt_one_helper(cmd, env_var, holder);
	}
	else
	{
		printf("insert an equal or go away man !!");
	}
	return (1);
}
