/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:44:27 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 10:47:15 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	display_sorted_env_vars(t_env **envv, int out_file)
{
	t_env	*aff;

	aff = (*envv);
	sort_alpha(envv, out_file);
}

int	sub_main(t_env **env_var, char *holder, char *trimed)
{
	char	*tmp;

	trimed = get_name_of_env_var(holder);
	tmp = trimed;
	trimed = ft_strjoin_non_free(tmp, "=");
	if (tmp)
		free(tmp);
	create_env(env_var, trimed);
	if (trimed)
		free(trimed);
	return (1);
}

int	export_helper_main(t_cmd *cmd, t_env **env_var, int index)
{
	char	*holder;
	char	*trimed;

	trimed = NULL;
	holder = cmd->cmd_w_arg[index + 1];
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
		return (sub_main(env_var, holder, trimed));
	else if (check_for_plus_to_export(holder) == 8)
		return (part_two_of_export(cmd, env_var));
	else if (check_if_there_is_a_dollar(holder) == 1)
		return (handle_dollar_export(cmd, env_var));
	else
		return (part_one_of_export(cmd, env_var));
	return (0);
}

void	ft_export_var(t_cmd *cmd, t_env **env_var, int out_file)
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
			display_sorted_env_vars(env_var, out_file);
		}
	}
	g_exit_status = 0;
}

int	get_index_of_env_var(t_env **envv, char *your_path)
{
	int		index;
	t_env	*tmp;
	char	*tp;
	char	*tp2;

	index = 0;
	tmp = (*envv);
	while (tmp)
	{
		tp = get_name_of_env_var(tmp->path_env);
		tp2 = get_name_of_env_var(your_path);
		if (ft_strcmp(tp, tp2) == 0)
		{
			free(tp);
			free(tp2);
			return (index);
		}
		index++;
		free(tp);
		free(tp2);
		tmp = tmp->next_env;
	}
	return (-1);
}
