/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mark.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:22:50 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 14:30:43 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	splited_join(char **ptr, char **splited, int i, int index)
{
	char	*tmp;
	char	*another_tmp;
	int		h;

	another_tmp = ft_itoa(g_exit_status);
	h = -1;
	tmp = *ptr;
	*ptr = ft_strdup_execution(&splited[i][index + 1]);
	if (tmp)
		free(tmp);
	tmp = *ptr;
	*ptr = ft_strjoin(another_tmp, splited[i]);
	free (another_tmp);
	if (tmp)
		free(tmp);
}

void	f1(char **splited, t_cmd *cmd, int ll)
{
	char	*tmp;
	int		i;

	i = 0;
	while (splited[++i])
	{
		if (i != 0)
		{
			tmp = splited[0];
			splited[0] = ft_strjoin(splited[0], splited[i]);
			free(tmp);
		}
	}
	splited[0][ft_strlen(splited[0])] = '\0';
	free(cmd->cmd_w_arg[ll]);
	cmd->cmd_w_arg[ll] = ft_strdup_execution(splited[0]);
	i = -1;
	while (splited[++i] != NULL)
		free(splited[i]);
	free(splited);
}

void	init_vars(int *index, int *i)
{
	*index = 0;
	*i = -1;
}

void	handle_q_mark(t_cmd *cmd)
{
	int		ll;
	int		i;
	int		index;
	char	**splited;

	ll = -1;
	while (cmd->cmd_w_arg[++ll] != NULL)
	{
		init_vars(&index, &i);
		if (search_for_status(cmd->cmd_w_arg[ll]) == 1)
		{
			splited = ft_split_execution(cmd->cmd_w_arg[ll], '$');
			while (splited[++i])
			{
				if (find_tab(splited[i]) == 0)
					splited_join(&splited[i], splited, i, index);
				else if (find_tab(splited[i]) == ft_strlen(splited[i]))
					splited[i] = ft_itoa(g_exit_status);
			}
			i = 0;
			f1(splited, cmd, ll);
		}
	}
}
