/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:42:31 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/07 15:31:13 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

// int find_path(char **envp)
// {
// 	int i =0;
// 	while (envp[i])
// 	{
// 		if(ft_strnstr(envp[i],"PATH=",5))
// 		{
// 			return (i);
// 		}
// 		i++;
// 	}
// 	return (-1);
// }

char	*get_env_from_list(t_env *env_var)
{
	t_env	*tmp;

	tmp = env_var;
	while (tmp)
	{
		if (ft_strcmp(get_name_of_env_var(tmp->path_env), "PATH") == 0)
		{
			return (tmp->path_env);
		}
		tmp = tmp->next_env;
	}
	return (NULL);
}

char	*get_path(char *cmd, t_env *envp)
{
	int		i;
	char	**env_path;
	char	*checkp;
	char	*tmp;
	i = -1;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	if (get_env_from_list(envp) == NULL)
		return (NULL);
	env_path = ft_split_execution(get_env_from_list(envp), ':');
	env_path[0] = ft_strtrim(env_path[0], "PATH=");
	while (env_path[++i])
		env_path[i] = ft_strjoin(env_path[i], "/");
	i = 0;
	while (env_path[i])
	{
		checkp = ft_strjoin(env_path[i], cmd);
		if (access(checkp, X_OK) == 0)
		{
			//free_split_in(env_path);
			return (checkp);
		}
		free(checkp);
		i++;
	}
	//free(checkp);
	//free_split_in(env_path);
	return (NULL);
}

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

// int main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	t_env *envv = ft_env(envp);
// 	//printf("path is : %s\n",get_path("cat",envv));
// 	// printf("%s\n",get_env_from_list(envv));
// }