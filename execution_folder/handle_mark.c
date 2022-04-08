/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mark.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:22:50 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/08 17:22:58 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	handle_q_mark(t_cmd *cmd)
{
	int		ll;
	int		i;
	int		index;
	int		j;
	char	**splited;

	ll = 0;
	while (cmd->cmd_w_arg[ll] != NULL)
	{
		j = 0;
		index = 0;
		i = 0;
		if (search_for_status(cmd->cmd_w_arg[ll]) == 1)
		{
			splited = ft_split_execution(cmd->cmd_w_arg[ll], '$');
			while (splited[i])
			{
				if (find_tab(splited[i]) == 0)
				{
					splited[i] = ft_strdup_execution(&splited[i][index + 1]);
					splited[i] = ft_strjoin(ft_itoa(exit_status), splited[i]);
				}
				else if (find_tab(splited[i]) == ft_strlen(splited[i]))
					splited[i] = ft_itoa(exit_status);
				i++;
			}
			i = 1;
			while (splited[i])
			{
				if (j != i)
					splited[j] = ft_strjoin(splited[j], splited[i]);
				i++;
			}
			cmd->cmd_w_arg[ll] = ft_strdup_execution(splited[j]);
		}
		ll++;
	}
}