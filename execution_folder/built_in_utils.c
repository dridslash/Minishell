/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:44:51 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/11 17:08:47 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	is_there_a_built_in(t_cmd *holder_nodes)
{
	if (holder_nodes->cmd_w_arg != NULL)
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
	}
	return (0);
}

char	**fill_envp(t_env *env_var)
{
	int		size;
	int		i;
	t_env	*tmp;
	char	**envp_c;

	size = 0;
	i = 0;
	tmp = env_var;
	while (tmp)
	{
		size++;
		tmp = tmp->next_env;
	}
	tmp = env_var;
	envp_c = (char **) malloc(sizeof(char *) * (size + 1));
	while (tmp)
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
	if (holder_nodes->cmd_w_arg != NULL)
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
	}
	return (NULL);
}
