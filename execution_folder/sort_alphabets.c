/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alphabets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:56:41 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/31 11:14:34 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int size_of_list(t_env **envv)
{
    int i = 0;
    t_env *tmp = (*envv);
    while(tmp)
    {
        i++;
        tmp = tmp->next_env;
    }
    return (i);
}

void sort_alpha(t_env **envv)
{
    int i = 0;
    int x = 0;
    int j = 0;
    int c = 0;
    t_env *pl = (*envv);
    char *tmp;
    char **holder = (char **) malloc(sizeof(char *) * (size_of_list(envv) + 1));
    while(i < size_of_list(envv) && pl)
    {
        holder[i] = ft_strdup(pl->path_env);
        i++;
        pl = pl->next_env;
    }
    holder[i] = NULL;
    i = 0;
    j = 0;
    while(holder[i])
    {
        j = i + 1;
        while(holder[j])
        {
                if(holder[i][0] > holder[j][0])
                {
                    tmp = holder[i];
                    holder[i] = holder[j];
                    holder[j] = tmp;
                }
            j++;
        }
        i++;
    }
    i = 0;
    j = 0;
    while(holder[i])
    {
        j = i + 1;
        while(holder[j])
        {
            if(holder[i][0] == holder[j][0])
            {
                while(holder[i][c] == holder[j][c])
                {
                    c++;
                }
            }
            else
            {
            if((holder[i][c] > holder[j][c]) && (holder[i][0] == holder[j][0]) && (ft_strcmp(holder[i],holder[j]) != 0))
            {
                tmp = holder[i];
                holder[i] = holder[j];
                holder[j] = tmp;
            }
            }
            j++;
        }
        c = 0;
        i++;
    }
    i = 0;
    while(holder[i])
    {
        printf("declare -x %s\n",holder[i]);
        i++;
    }
}

// int main(int argc , char **argv)
// {
//        int i = 1;
//        sort_alpha(argv);
//     //    while(argv[i])
//     //    {
//     //        printf("%s\n",argv[i]);
//     //        i++;
//     //    }
// }