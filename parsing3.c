/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:21:01 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/01 11:03:10 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	here_doc_p(char **split_input, int *i, t_cmd *cmd)
{
	cmd->how_many_here_doc += 1;
	push_limiter(split_input[*i + 1], cmd);
	cmd->in_file_op = -1;
	(*i)++;
}

void	push_limiter(char *to_push, t_cmd *cmd)
{
	char	**s;
	int		i;

	i = -1;
	if (cmd->limiters == NULL)
	{
		cmd->limiters = malloc(sizeof(char *) * 2);
		cmd->limiters[0] = ft_strdup(to_push);
		cmd->limiters[1] = NULL;
		return ;
	}
	s = malloc(sizeof(char *) * (len_dp(cmd->limiters) + 2));
	while (cmd->limiters[++i] != NULL)
		s[i] = ft_strdup(cmd->limiters[i]);
	s[i] = ft_strdup(to_push);
	s[i + 1] = NULL;
	free(cmd->limiters);
	cmd->limiters = s;
}
