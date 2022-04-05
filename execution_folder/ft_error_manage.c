/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:10:22 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/05 19:54:30 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

char *get_curr_dir(t_cmd *cmd)
{
    char	current_dir[FILE_N_MAX];
    char *dir;
    current_dir[FILE_N_MAX - 1] = '\0';
	getcwd(current_dir, FILE_N_MAX);
    dir  = current_dir;
    return (dir);
}

void ft_error(t_cmd *cmd,t_env *env_var)
{
        if (ft_strcmp(cmd->cmd_w_arg[0],"") == 0)
        {
        write(2, ">> shell :",10);
        write(2, cmd->cmd_w_arg[0], ft_strlen(cmd->cmd_w_arg[0]));
        write(2, ":",1);
        write(2,"command not found\n",18);
        exit (0);
        }
        if (access(get_path(cmd->cmd_w_arg[0],env_var),X_OK) == -1)
        {
            write(2, ">> shell :",10);
            write(2, cmd->cmd_w_arg[0], ft_strlen(cmd->cmd_w_arg[0]));
            write(2, ":",1);
            write(2,"command not found\n",18);
            exit (0);
        }
}