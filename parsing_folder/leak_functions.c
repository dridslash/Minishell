/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:18:24 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/04 19:51:56 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(char **p, char *p2, int n, t_cmd *com)
{
	int	i;

	i = -1;
	while (++i < n + 1)
	{
		if (p[i])
			free(p[i]);
	}
	free(p);
	free(p2);
	free_com_list(com);
}

void	free_split_in(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_double_p(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	free_com_list(t_cmd *com)
{
	t_cmd	*tmp;

	while (com != NULL)
	{
		if (com->here_doc_char)
			free(com->here_doc_char);
		if (com->limiters)
			free_split_in(com->limiters);
		if (com->cmd_w_arg)
			free_split_in(com->cmd_w_arg);
		tmp = com;
		com = com->next;
		free(tmp);
	}
}
