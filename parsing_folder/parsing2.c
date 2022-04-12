/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:23:35 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/09 13:05:48 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_files(char **split_input2, int *i, t_cmd *cmd)
{
	if (ft_strcmp(split_input2[*i], "<") == 0)
		in_output_red(cmd, split_input2[*i + 1], 'i');
	else if (ft_strcmp(split_input2[*i], ">") == 0)
		in_output_red(cmd, split_input2[*i + 1], 'o');
	else if (ft_strcmp(split_input2[*i], ">>") == 0)
		append_red(cmd, split_input2[*i + 1]);
	else if (ft_strcmp(split_input2[*i], "<>") == 0)
		in2(cmd, split_input2[*i + 1]);
	(*i)++;
}

void	append_red(t_cmd *cmd, char *file)
{
	cmd->out_file_op = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (cmd->out_file_op < 0)
	{
		perror(file);
		cmd->out_file_op = -100;
	}
}

void	in_output_red(t_cmd *cmd, char *file, char option)
{
	if (option == 'o')
	{
		cmd->out_file_op = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (cmd->out_file_op < 0)
		{
			perror(file);
			cmd->out_file_op = -100;
		}
	}
	else if (option == 'i')
	{
		cmd->in_file_op = open(file, O_RDONLY, 0644);
		if (cmd->in_file_op < 0)
		{
			perror(file);
			cmd->in_file_op = -100;
		}
	}
}

void	push_string(char *to_push, t_cmd *cmd)
{
	char	**s;
	int		i;

	i = -1;
	if (cmd->cmd_w_arg == NULL)
	{
		cmd->cmd_w_arg = malloc(sizeof(char *) * 2);
		cmd->cmd_w_arg[0] = ft_strdup_parsing(to_push);
		cmd->cmd_w_arg[1] = NULL;
		return ;
	}
	s = malloc(sizeof(char *) * (len_dp(cmd->cmd_w_arg) + 2));
	while (cmd->cmd_w_arg[++i] != NULL)
		s[i] = ft_strdup_parsing(cmd->cmd_w_arg[i]);
	s[i] = ft_strdup_parsing(to_push);
	s[i + 1] = NULL;
	i = -1;
	while (cmd->cmd_w_arg[++i])
		free(cmd->cmd_w_arg[i]);
	free(cmd->cmd_w_arg);
	cmd->cmd_w_arg = s;
}

int	len_dp(char **p)
{
	int	i;

	i = 0;
	while (p[i] != NULL)
		i++;
	return (i);
}
