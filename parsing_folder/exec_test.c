/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:18:33 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/03 15:12:31 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec_test.h"

//EXECUTION
t_env	*ft_env(char **envi)
{
    int	i;

	i = 0;
	t_env *main_env = malloc(sizeof(t_env));
	main_env = NULL;
    while(envi[i])
    {
		create_env(&main_env,envi[i]);
		i++;
    }
    return (main_env);
}

t_env *bring_last(t_env *father_of_env)
{
    while(father_of_env->next_env != NULL)
    {
        father_of_env = father_of_env->next_env;
    }
    return (father_of_env);
}

void    create_env(t_env **envv, char *path_env)
{
    t_env    *tmp;
    t_env    *element_path;

    element_path = malloc(sizeof(t_env));
    element_path->path_env = path_env;
    tmp = (*envv);
    if (!(*envv))
    {
        (*envv) = element_path;
        element_path->next_env = NULL;
        free(tmp);
        return ;
    }
    bring_last((*envv))->next_env = element_path;
    element_path->next_env = NULL;
}

// char *search_in_env(t_env **envv,char * your_var)
// {
//     t_env *aff = (*envv);
//     while(aff)
//              {
//                  if(ft_strcmp(get_name_of_env_var(aff->path_env),get_name_of_env_var(your_var)) == 0)
//                  {
//                      return(get_after_equal(aff->path_env));
//                  }
//                  aff = aff->next_env;
//              }
//     return (NULL);
// }

// int     ft_strcmp(char  *s1,char    *s2)
// {
// 	while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*s1 - *s2);
// }

// char *get_name_of_env_var(char *tb)
// {
//     int  i = 0;
//    // int index_tmp = 2;
//     char *chr = ft_strdup_parsing(tb);
//     while(chr[i])
//     {
//         if(chr[i] == '=' || (chr[i] == '+' && chr[i + 1] == '='))
//         {
//         chr[i] = '\0';
//         break;
//         }
//         i++;
//     }
//     return (chr);
// }

// char *get_after_equal(char *your_path)
// {
//     int  i =0;
//     while(your_path[i])
//     {
//         if(your_path[i] == '=')
//         {
//             return (&your_path[i + 1]);
//         }
//         i++;
//     }
//     return (NULL);
// }

// char *get_after_dollar(char *your_path)
// {
//     int  i;

// 	i = 0;
//     while (your_path[i])
//     {
//         if (your_path[i] == '$')
//             return (&your_path[i + 1]);
//         i++;
//     }
//     return (NULL);
// }
//EXECUTION
