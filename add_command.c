/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:00:08 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/15 10:09:40 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_cmd *bring_last(t_cmd *father_of_cmds)
{
    while(father_of_cmds->next != NULL)
    {
        father_of_cmds = father_of_cmds->next;
    }
    return (father_of_cmds);
}

void add_cmd(t_cmd **father_of_cmds, int in_file_op, int out_file_op, char **cmd_w_arg)
{
    t_cmd *small_cmd;
    t_cmd *last;
    small_cmd = malloc(sizeof(t_cmd));
    small_cmd->in_file_op = in_file_op;
    small_cmd->out_file_op = out_file_op;
    small_cmd->cmd_w_arg = cmd_w_arg;
    if(!(*father_of_cmds))
    {
        (*father_of_cmds) = small_cmd;
        small_cmd->next = NULL;
    }
    last = bring_last((*father_of_cmds));
    last->next = small_cmd;
    small_cmd->next = NULL;
}