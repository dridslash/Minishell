/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_her_doccc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:47:23 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/13 13:05:39 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	execute_her_docc(t_cmd *holder_nodes,
	t_env *env_var, int *it_it_fd, int *pipes)
{
	if (holder_nodes->out_file_op == -100
		|| holder_nodes->in_file_op == -100
		|| holder_nodes->cmd_w_arg == NULL)
		exit (1);
	execution_helper_main(holder_nodes,
		it_it_fd, pipes, &env_var);
	execve(get_path(holder_nodes->cmd_w_arg[0], env_var),
		holder_nodes->cmd_w_arg, fill_envp(env_var));
}

void	in_ss(int *iterate, int *iterate_for_fds)
{
	*iterate = 0;
	*iterate_for_fds = 0;
}
