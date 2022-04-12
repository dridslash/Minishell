/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:23:55 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 17:11:49 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

// t_env *bring_last(t_env *father_of_env)
// {
//     while(father_of_env->next_env != NULL)
//     {
//         father_of_env = father_of_env->next_env;
//     }
//     return (father_of_env);
// }

// void    create_env(t_env **envv,char *path_env)
// {
//     t_env *last_env_var = malloc(sizeof(t_env));
//     t_env *element_path = malloc(sizeof(t_env));
//     element_path->path_env = path_env;
//     if(!(*envv))
//     {
//         (*envv) = element_path;
//         element_path->next_env = NULL;
//     }
//     last_env_var = bring_last((*envv));
//     last_env_var->next_env = element_path;
//     element_path->next_env = NULL;
// }

// t_env *ft_env(char **envi)
// {
//     int i = 0;
//     t_env *main_env = malloc(sizeof(t_env));
//     main_env = NULL;
//     while(envi[i])
//     {
//     create_env(&main_env,envi[i]);
//     i++;
//     }
//     return (main_env);
// }

void	env_show(t_cmd *cmd, t_env **env_var, int out_file)
{
	int		index;
	t_env	*tmp;

	index = 0;
	tmp = (*env_var);
	if ((ft_strcmp(cmd->cmd_w_arg[0], "env") == 0
			|| ft_strcmp(cmd->cmd_w_arg[0], "ENV") == 0)
		&& (cmd->cmd_w_arg[index + 1] == NULL))
	{
		while (tmp != NULL)
		{
			write(out_file, tmp->path_env, ft_strlen(tmp->path_env));
			write(out_file, "\n", 1);
			tmp = tmp->next_env;
		}
	}
	else
		printf("%s : No such file or directory\n",
			cmd->cmd_w_arg[index + 1]);
	g_exit_status = 0;
	return ;
}
