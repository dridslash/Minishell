/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_part_one_of_export.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:57:04 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 17:29:49 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	free_trio_iterate(char **tp, char **tp2, char **tp3, t_env **aff)
{
	(void)tp3;
	free(*tp);
	(*aff) = (*aff)->next_env;
	free(*tp2);
}

void	just_free(char **tp3, char **tp2, char **tp, char **tmp4)
{
	free(*tp3);
	free(*tp2);
	free(*tp);
	if (*tmp4)
		free(*tmp4);
}

void	export_pt_one_helper(t_cmd *cmd,
		t_env **env_var, char *holder, int locker)
{
	t_env	*aff;
	char	*tp2;
	char	*tp;
	char	*tp3;
	char	*tmp4;

	aff = (*env_var);
	(void)cmd;
	while (aff)
	{
		tp = get_name_of_env_var(aff->path_env);
		tp2 = get_name_of_env_var(holder);
		if (ft_strcmp(tp, tp2) == 0)
		{
				tp3 = get_name_of_env_var(aff->path_env);
				tmp4 = aff->path_env;
				aff->path_env = ft_strdup_execution(holder);
			just_free(&tp3, &tp2, &tp, &tmp4);
				locker++;
			break ;
		}
		free_trio_iterate(&tp, &tp2, &tp3, &aff);
	}
	if (locker == 0)
		create_env(env_var, holder);
}

int	part_one_of_export(t_cmd *cmd, t_env **env_var)
{
	int		i;
	int		index;
	char	*holder;
	int		locker;

	index = 0;
	locker = 0;
	holder = cmd->cmd_w_arg[index + 1];
	i = 0;
	if (cmd->cmd_w_arg[index + 1] != NULL
		&& get_equal_index(cmd->cmd_w_arg[index + 1]) != -1)
	{
		export_pt_one_helper(cmd, env_var, holder, locker);
	}
	return (1);
}
