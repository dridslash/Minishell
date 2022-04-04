/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:44:27 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 17:41:38 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	display_sorted_env_vars(t_env **envv)
{
	t_env	*aff;

	aff = (*envv);
	sort_alpha(envv);
}

int	sub_main(t_cmd *cmd, t_env **env_var, char *holder, char *trimed)
{
	trimed = get_name_of_env_var(holder);
	trimed = ft_strjoin_non_free(trimed, "=");
	create_env(env_var, trimed);
	return (1);
}

int	export_helper_main(t_cmd *cmd, t_env **env_var, int index)
{
	char	*holder;
	char	*trimed;

	holder = cmd->cmd_w_arg[index + 1];
	trimed = ft_strdup_execution("");
	if (check_is_exportable(holder) == 11
		|| check_errors_export(holder) == 2
		|| check_errors_export(holder) == 1
		|| check_errors_export(holder) == 3
		|| check_errors_export(holder) == 4
		|| check_errors_export(holder) == 9
		|| check_errors_export(holder) == 10)
	{
		write(2, "export Error\n", 13);
		return (1);
	}
	else if (check_errors_export(holder) == 7)
		return (sub_main(cmd, env_var, holder, trimed));
	else if (check_for_plus_to_export(holder) == 8)
		return (part_two_of_export(cmd, env_var));
	else if (check_if_there_is_a_dollar(holder) == 1)
		return (handle_dollar_export(cmd, env_var));
	else
		return (part_one_of_export(cmd, env_var));
	return (0);
}

void	ft_export_var(t_cmd *cmd, t_env **env_var)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	if (ft_strcmp(cmd->cmd_w_arg[0], "export") == 0)
	{
		if (cmd->cmd_w_arg[index + 1] != NULL)
		{
			if (export_helper_main(cmd, env_var, index) == 1)
				return ;
		}
		else
		{
			display_sorted_env_vars(env_var);
		}
	}
}

int	get_index_of_env_var(t_env **envv, char *your_path)
{
	int		index;
	t_env	*tmp;

	index = 0;
	tmp = (*envv);
	while (tmp)
	{
		if (ft_strcmp(get_name_of_env_var(tmp->path_env),
				get_name_of_env_var(your_path)) == 0)
		{
			return (index);
		}
		index++;
		tmp = tmp->next_env;
	}
	return (-1);
}
