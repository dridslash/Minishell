/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:11:09 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/08 14:11:36 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	is_there_a_built_in(t_cmd *holder_nodes)
{
	if (ft_strcmp(holder_nodes->cmd_w_arg[0], "cd") == 0
		|| ft_strcmp(holder_nodes->cmd_w_arg[0], "export") == 0
		|| ft_strcmp(holder_nodes->cmd_w_arg[0], "pwd") == 0
		|| ft_strcmp(holder_nodes->cmd_w_arg[0], "unset") == 0
		|| ft_strcmp(holder_nodes->cmd_w_arg[0], "echo") == 0
		|| ft_strcmp(holder_nodes->cmd_w_arg[0], "exit") == 0
		|| ft_strcmp(holder_nodes->cmd_w_arg[0], "env") == 0)
	{
		return (1);
	}
	return (0);
}

char **fill_envp(t_env *env_var)
{
	int size = 0;
	int i = 0;
	t_env *tmp = env_var;
	char **envp_c;
	while(tmp)
	{
		size++;
		tmp = tmp->next_env;
	}
	tmp = env_var;
	envp_c = (char **) malloc(sizeof(char *) * (size + 1));
	while(tmp)
	{
		envp_c[i] = ft_strdup_execution(tmp->path_env);
		i++;
		tmp = tmp->next_env;
	}
	envp_c[i] = NULL;
	return (envp_c);
}

// void	just_close(int *pipes, int original_cmds)
// {
//     int j;

//     j = 0;
//     while (j < (original_cmds - 1) * 2)
//     {
//         close(pipes[j]);
//         j++;
//     }
// }

char	*which_built_in(t_cmd *holder_nodes)
{
	if (ft_strcmp(holder_nodes->cmd_w_arg[0], "cd") == 0)
		return ("cd");
	else if (ft_strcmp(holder_nodes->cmd_w_arg[0], "export") == 0)
		return ("export");
	else if (ft_strcmp(holder_nodes->cmd_w_arg[0], "unset") == 0)
		return ("unset");
	else if (ft_strcmp(holder_nodes->cmd_w_arg[0], "exit") == 0)
		return ("exit");
	else if (ft_strcmp(holder_nodes->cmd_w_arg[0], "echo") == 0)
		return ("echo");
	else if (ft_strcmp(holder_nodes->cmd_w_arg[0], "pwd") == 0)
		return ("pwd");
	else if (ft_strcmp(holder_nodes->cmd_w_arg[0], "env") == 0)
		return ("env");
	return (NULL);
}

int	execut_helper_one(t_cmd *holder_nodes,
			int iterate, int *pipes, int iterate_for_fds, t_env **env_var)
{
	int index = 0;
	if (iterate == 0)
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
		else
		execute_cmds_close_files(holder_nodes->in_file_op,
			pipes[iterate_for_fds + 1],
			(holder_nodes->size_of_list - 1) * 2, pipes);
	}
	else if (iterate + 1 == holder_nodes->size_of_list)
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
		else if(holder_nodes->in_file_op > 0)
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
		else if(holder_nodes->in_file_op > 0)
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
	return (1);
}

int	execute_commands(t_cmd *cmd, t_env **env_var, int *pipes, int original_cmds)
{
	t_cmd	*holder_nodes;
	int		iterate;
	int		iterate_for_fds;
	int		*pids;
	int		check;

	holder_nodes = cmd;
	pids = malloc(sizeof(int) * original_cmds);
	iterate = 0;
	iterate_for_fds = 0;
	while (iterate < original_cmds && (holder_nodes))
	{
		holder_nodes->size_of_list = original_cmds;
		pids[iterate] = fork();
		if (pids[iterate] == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			if (execut_helper_one(holder_nodes, iterate, pipes, iterate_for_fds, env_var) != 0)
			{
			execve(get_path(holder_nodes->cmd_w_arg[0], (*env_var)),
				holder_nodes->cmd_w_arg, fill_envp((*env_var)));
			}
			return (0);
		}
		iterate++;
		iterate_for_fds += 2;
		holder_nodes = holder_nodes->next;
	}
	free(pipes);
	return (0);
}

int	execute_command(t_cmd *cmd, t_env **env_var, int original_cmds)
{
	int	pid;

	pid = 0;
	pid = fork();
		// if (is_there_a_built_in(cmd))
		// {
		// 		if (ft_strcmp(which_built_in(cmd),"cd") == 0)
		// 		{
		// 			ft_cd(cmd, (*env_var));
		// 			return (0);
		// 		}
		// 			else if (ft_strcmp(which_built_in(cmd),"export") == 0)
		// 		{
		// 				ft_export_var(cmd, env_var, cmd->out_file_op);
		// 				return (0);
		// 		}
		// 		// 	else if (ft_strcmp(which_built_in(cmd),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
		// 		// {
		// 		// 	ft_pwd(cmd, (*env_var), cmd->out_file_op);
		// 		// 	write(cmd->out_file_op,"\n",1);
		// 		// 		return (0);
		// 		// }
		// 			else if (ft_strcmp(which_built_in(cmd),"unset") == 0)
		// 		{
		// 				ft_unset(env_var, cmd);
		// 				return (0);
		// 		}
		// 		else if (ft_strcmp(which_built_in(cmd),"env") == 0)
		// 		{
		// 			//t_env *tmp;

		// 			//tmp = (*env_var);
		// 			// while (tmp != NULL)
		// 			// {
		// 			// 	printf("%s\n",tmp->path_env);
		// 			// 	tmp = tmp->next_env;
		// 			// }
		// 			printf("\n\n\n");
		// 			env_show(cmd, env_var , 1);
		// 			return (0);
		// 		}
		// 		else if(ft_strcmp(which_built_in(cmd),"echo") == 0)
		// 		{
		// 			ft_echo(cmd , cmd->out_file_op);
		// 			return (0);
		// 		}
		// }
	// else if (is_there_a_built_in(cmd) != 1)
	// {
	if (pid == 0)
	{
		if (cmd->out_file_op == -100)
		{
			return (0);
		}
			// if (ft_strcmp(which_built_in(cmd),"pwd") == 0 && (get_index_of_env_var(env_var, "PATH") == -1))
			// 	{
			// 		ft_pwd(cmd, (*env_var), cmd->out_file_op);
			// 		write(cmd->out_file_op,"\n",1);
			// 			return (0);
			// 	}
		dup2(cmd->in_file_op, 0);
		dup2(cmd->out_file_op, 1);
		ft_error(cmd, (*env_var));
		execve(get_path(cmd->cmd_w_arg[0], (*env_var)), cmd->cmd_w_arg, fill_envp((*env_var)));
		return (0);
	}
	// }
	waitpid(pid, NULL, 0);
	return (0);
}
