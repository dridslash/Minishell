/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:29:06 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/10 10:47:39 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec_test.h"

//EXECUTION
t_env	*ft_env(char **envi)
{
	int		i;
	t_env	*main_env;

	i = 0;
	main_env = NULL;
	while (envi[i])
	{
		create_env(&main_env, envi[i]);
		i++;
	}
	return (main_env);
}

t_env	*bring_last(t_env *father_of_env)
{
	while (father_of_env->next_env != NULL)
		father_of_env = father_of_env->next_env;
	return (father_of_env);
}

void	create_env(t_env **envv, char *path_env)
{
	t_env	*tmp;
	t_env	*element_path;

	element_path = malloc(sizeof(t_env));
	element_path->path_env = ft_strdup_execution(path_env);
	element_path->next_env = NULL;
	if (!(*envv))
	{
		tmp = (*envv);
		(*envv) = element_path;
		element_path->next_env = NULL;
		free(tmp);
		return ;
	}
	bring_last((*envv))->next_env = element_path;
}

// char	*search_in_env(t_env **envv, char *your_var)
// {
// 	char	*tmp1;
// 	char	*tmp2;
// 	t_env	*aff;

// 	aff = (*envv);
// 	while (aff)
// 	{
// 		tmp1 = get_name_of_env_var(aff->path_env);
// 		tmp2 = get_name_of_env_var(your_var);
// 		if (ft_strcmp(tmp1, tmp2) == 0)
// 		{
// 			free(tmp1);
// 			free(tmp2);
// 			return (get_after_equal(aff->path_env));
// 		}
// 		free(tmp1);
// 		free(tmp2);
// 		aff = aff->next_env;
// 	}
// 	return (NULL);
// }

// int	ft_strcmp(char *s1, char *s2)
// {
// 	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*s1 - *s2);
// }

// char	*get_name_of_env_var(char *tb)
// {
// 	int		i;
// 	int		index_tmp;
// 	char	*chr;

// 	i = 0;
// 	index_tmp = 2;
// 	chr = ft_strdup(tb);
// 	while (chr[i])
// 	{
// 		if (chr[i] == '=' || (chr[i] == '+' && chr[i + 1] == '='))
// 		{
// 			chr[i] = '\0';
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (chr);
// }

// char	*get_after_equal(char *your_path)
// {
// 	int	i;

// 	i = 0;
// 	while (your_path[i])
// 	{
// 		if (your_path[i] == '=')
// 			return (&your_path[i + 1]);
// 		i++;
// 	}
// 	return (NULL);
// }

// int	ft_strlen(char *s)
// {
// 	int	len;

// 	len = 0;
// 	while (*s != '\0')
// 	{
// 		len++;
// 		s++;
// 	}
// 	return (len);
// }

// char	*get_after_dollar(char *your_path)
// {
// 	int	i;

// 	i = 0;
// 	while (your_path[i])
// 	{
// 		if (your_path[i] == '$')
// 			return (&your_path[i + 1]);
// 		i++;
// 	}
// 	return (NULL);
// }
//EXECUTION
