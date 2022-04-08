/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:30:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/07 20:03:42 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	execution_help_of_hlp(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes, t_env **env_var)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		ft_error(holder_nodes, (*env_var));
		if (is_there_a_built_in(holder_nodes))
		{
				if (ft_strcmp(which_built_in(holder_nodes),"cd") == 0)
					exit (0);
					else if (ft_strcmp(which_built_in(holder_nodes),"export") == 0)
				{
						ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
				{
					ft_pwd(holder_nodes, (*env_var), holder_nodes->out_file_op);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"unset") == 0)
				{
						exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"exit") == 0)
				{
					exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"env") == 0)
				{
					env_show(holder_nodes, env_var , 1);
					exit (0);
				}
				else if(ft_strcmp(which_built_in(holder_nodes),"echo") == 0)
				{
					ft_echo(holder_nodes , holder_nodes->out_file_op);
					exit (0);
				}
		}
		if (holder_nodes->out_file_op > 1)
		{
			execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		if (holder_nodes->in_file_op > -1)
		{
			execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		else
		{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
		}
	}
	else
	{
		ft_error(holder_nodes, (*env_var));
		if (is_there_a_built_in(holder_nodes))
		{
				if (ft_strcmp(which_built_in(holder_nodes),"cd") == 0)
				{
					ft_cd(holder_nodes, (*env_var));
					return (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"export") == 0)
				{
						ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
						return (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
				{
					ft_pwd(holder_nodes, (*env_var), holder_nodes->out_file_op);
					write(holder_nodes->out_file_op,"\n",1);
						return (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"unset") == 0)
				{
						ft_unset(env_var, holder_nodes);
						return (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"env") == 0)
				{
					env_show(holder_nodes, env_var , 1);
					return (0);
				}
				else if(ft_strcmp(which_built_in(holder_nodes),"echo") == 0)
				{
					ft_echo(holder_nodes , holder_nodes->out_file_op);
					return (0);
				}
		}
		execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	return (0);
}

void	execution_help_of_hlp_two(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes, t_env **env_var)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		ft_error(holder_nodes, (*env_var));
		if (is_there_a_built_in(holder_nodes))
		{
				if (ft_strcmp(which_built_in(holder_nodes),"cd") == 0)
					exit (0);
					else if (ft_strcmp(which_built_in(holder_nodes),"export") == 0)
				{
						ft_export_var(holder_nodes, env_var, pipes[iterate_for_fds + 1]);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
				{
					ft_pwd(holder_nodes, (*env_var),pipes[iterate_for_fds + 1]);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"unset") == 0)
				{
						exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"exit") == 0)
				{
					exit_status = -1000;
					exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"env") == 0)
				{
					env_show(holder_nodes, env_var , 1);
					exit (0);
				}
				else if(ft_strcmp(which_built_in(holder_nodes),"echo") == 0)
				{
					ft_echo(holder_nodes ,pipes[iterate_for_fds + 1]);
					exit (0);
				}
		}
		if (holder_nodes->out_file_op > 1)
		{
			execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		if (holder_nodes->in_file_op > -1)
		{
			execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		else
		{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
		}
	}
	else
	{
		ft_error(holder_nodes, (*env_var));
		if (is_there_a_built_in(holder_nodes))
		{
				if (ft_strcmp(which_built_in(holder_nodes),"cd") == 0)
					exit (0);
					else if (ft_strcmp(which_built_in(holder_nodes),"export") == 0)
				{
						ft_export_var(holder_nodes, env_var, pipes[iterate_for_fds + 1]);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
				{
					ft_pwd(holder_nodes, (*env_var), pipes[iterate_for_fds + 1]);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"unset") == 0)
				{
						exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"exit") == 0)
				{
					exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"env") == 0)
				{
					env_show(holder_nodes, env_var , 1);
					exit (0);
				}
				else if(ft_strcmp(which_built_in(holder_nodes),"echo") == 0)
				{
					ft_echo(holder_nodes , pipes[iterate_for_fds + 1]);
					exit (0);
				}
		}
		if (holder_nodes->out_file_op > 1)
		{
			execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		execute_cmds_close_files(holder_nodes->in_file_op,
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
}

void	execution_hlp_main_one(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes, t_env **env_var)
{
	if (iterate + 1 == holder_nodes->size_of_list)
	{
		execution_help_of_hlp(holder_nodes, iterate_for_fds, iterate, pipes , env_var);
	}
	else
	{
		execution_help_of_hlp_two(holder_nodes,
			iterate_for_fds, iterate, pipes, env_var);
	}
}

void	execution_hlp_main_two(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes, t_env **env_var)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		ft_error(holder_nodes, (*env_var));
		if (is_there_a_built_in(holder_nodes))
		{
				if (ft_strcmp(which_built_in(holder_nodes),"cd") == 0)
					exit (0);
					else if (ft_strcmp(which_built_in(holder_nodes),"export") == 0)
				{
						ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
				{
					ft_pwd(holder_nodes, (*env_var), holder_nodes->out_file_op);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"unset") == 0)
				{
						exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"exit") == 0)
				{
					exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"env") == 0)
				{
					env_show(holder_nodes, env_var , 1);
					exit (0);
				}
				else if(ft_strcmp(which_built_in(holder_nodes),"echo") == 0)
				{
					ft_echo(holder_nodes , holder_nodes->out_file_op);
					exit (0);
				}
		}
		if (holder_nodes->out_file_op > 1)
		{
			execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		if (holder_nodes->in_file_op > -1)
		{
			execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		else
		{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
		}
	}
	else
	{
		ft_error(holder_nodes, (*env_var));
		if (is_there_a_built_in(holder_nodes))
		{
				if (ft_strcmp(which_built_in(holder_nodes),"cd") == 0)
					exit (0);
					else if (ft_strcmp(which_built_in(holder_nodes),"export") == 0)
				{
						ft_export_var(holder_nodes, env_var, holder_nodes->out_file_op);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
				{
					ft_pwd(holder_nodes, (*env_var),holder_nodes->out_file_op);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"unset") == 0)
				{
						exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"exit") == 0)
				{
					exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"env") == 0)
				{
					env_show(holder_nodes, env_var , 1);
					exit (0);
				}
				else if(ft_strcmp(which_built_in(holder_nodes),"echo") == 0)
				{
					ft_echo(holder_nodes , 1);
					exit (0);
				}
		}
		if (holder_nodes->out_file_op > 1)
		{
			execute_cmds_close_files(pipes[iterate_for_fds - 2],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		if(holder_nodes->in_file_op > 0)
		{
			execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		else
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
}

void	exectuion_hlp_main_three(t_cmd *holder_nodes,
int iterate_for_fds, int iterate, int *pipes, t_env **env_var)
{
	if (holder_nodes->how_many_here_doc > 0)
	{
		ft_error(holder_nodes, (*env_var));
		if (is_there_a_built_in(holder_nodes))
		{
				if (ft_strcmp(which_built_in(holder_nodes),"cd") == 0)
					exit (0);
					else if (ft_strcmp(which_built_in(holder_nodes),"export") == 0)
				{
						ft_export_var(holder_nodes, env_var,pipes[iterate_for_fds + 1]);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
				{
					ft_pwd(holder_nodes, (*env_var), pipes[iterate_for_fds + 1]);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"unset") == 0)
				{
						exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"exit") == 0)
				{
					exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"env") == 0)
				{
					env_show(holder_nodes, env_var , 1);
					exit (0);
				}
				else if(ft_strcmp(which_built_in(holder_nodes),"echo") == 0)
				{
					ft_echo(holder_nodes , pipes[iterate_for_fds + 1]);
					exit (0);
				}
		}
		if (holder_nodes->out_file_op > 1)
		{
			execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		if (holder_nodes->in_file_op > -1)
		{
			execute_cmds_close_files(holder_nodes->in_file_op,
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		else
		{
		execute_cmds_close_files(holder_nodes->fd_her_doc[0],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		close(holder_nodes->fd_her_doc[0]);
		close(holder_nodes->fd_her_doc[1]);
		}
	}
	else
	{
		ft_error(holder_nodes, (*env_var));
		if (is_there_a_built_in(holder_nodes))
		{
				if (ft_strcmp(which_built_in(holder_nodes),"cd") == 0)
					exit (0);
					else if (ft_strcmp(which_built_in(holder_nodes),"export") == 0)
				{
						ft_export_var(holder_nodes, env_var, pipes[iterate_for_fds + 1]);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
				{
					ft_pwd(holder_nodes, (*env_var), pipes[iterate_for_fds + 1]);
						exit (0);
				}
					else if (ft_strcmp(which_built_in(holder_nodes),"unset") == 0)
				{
						exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"exit") == 0)
				{
					exit (0);
				}
				else if (ft_strcmp(which_built_in(holder_nodes),"env") == 0)
				{
					env_show(holder_nodes, env_var , 1);
					exit (0);
				}
				else if(ft_strcmp(which_built_in(holder_nodes),"echo") == 0)
				{
					ft_echo(holder_nodes , pipes[iterate_for_fds + 1]);
					exit (0);
				}
		}
		if (holder_nodes->out_file_op > 1)
		{
			execute_cmds_close_files(pipes[iterate_for_fds - 2],
			holder_nodes->out_file_op,
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		if(holder_nodes->in_file_op > 0)
		{
			execute_cmds_close_files(holder_nodes->in_file_op,
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
		}
		else
		execute_cmds_close_files(pipes[iterate_for_fds - 2],
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
}
