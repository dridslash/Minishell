/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:42:31 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/14 14:12:17 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int find_path(char **envp)
{
	int i =0;
	while (envp[i])
	{
		if(ft_strnstr(envp[i],"PATH=",5))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**env_path;
	char	*checkp;

	i = 0;
	if(access(cmd,X_OK) == 0)
		return (cmd);
	
	env_path = ft_split(envp[find_path(envp)], ':');
	env_path[0] = ft_strtrim(env_path[0], "PATH=");
	while (env_path[i])
	{
		env_path[i] = ft_strjoin(env_path[i], "/");
		i++;
	}
	i = 0;
	while (env_path[i])
	{
		checkp = ft_strjoin(env_path[i], cmd);
		if (access(checkp, X_OK) == 0)
			return (checkp);
		free(checkp);
		i++;
	}
	return (NULL);
}

