/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_imp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:22:42 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/18 15:09:15 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h" 

void ft_pwd()
{
    char current_dir[FILE_N_MAX];
    current_dir[FILE_N_MAX - 1] = '\0';
    getcwd(current_dir,FILE_N_MAX);
    printf("%s\n",current_dir);
}

t_env *bring_last(t_env *father_of_env)
{
    while(father_of_env->next_env != NULL)
    {
        father_of_env = father_of_env->next_env;
    }
    return (father_of_env);
}

void    create_env(t_env **envv,char *path_env)
{
    t_env *last_env_var = malloc(sizeof(t_env));
    t_env *element_path = malloc(sizeof(t_env));
    element_path->path_env = path_env;
    if(!(*envv))
    {
        (*envv) = element_path;
        element_path->next_env = NULL;
    }
    last_env_var = bring_last((*envv));
    last_env_var->next_env = element_path;
    element_path->next_env = NULL;
}

void ft_cd(int argc, char **argv)
{
    char *get_home = getenv("HOME");
    int index_tmp = 1;
     char current_dir[FILE_N_MAX];
     current_dir[FILE_N_MAX - 1] = '\0';
     getcwd(current_dir,FILE_N_MAX);
     if(ft_strcmp(argv[index_tmp],"cd") == 0)
     {
     if(argv[index_tmp + 1] != NULL)
     {
        if(chdir(argv[index_tmp + 1]) != 0)
         perror("my shell : cd ");
     }
     else
     chdir(get_home);
     }
     printf("%s\n",getcwd(current_dir,FILE_N_MAX));
}

t_env *ft_env(char **envi)
{
    int i = 0;
    t_env *main_env = malloc(sizeof(t_env));
    main_env = NULL;
    while(envi[i])
    {
    create_env(&main_env,envi[i]);
    i++;
    }
    return main_env;
}

int get_equal_index(char *table)
{
    int i = 0;
    while(table[i])
    {
        if(table[i] == '=')
            return (i);
        i++;
    }
    return (-1);
}

void ft_export_var(t_env **envv,char **argv)
{
    int i =0;
    int pattern_counter = 0;
    int index_tmp = 1;
    t_env *tmp = (*envv);
    t_env *aff = (*envv);
    if(ft_strcmp(argv[index_tmp],"export") == 0)
     {
         if(argv[index_tmp + 1] != NULL)
         {
             if (ft_strnstr())
         }
     }
    while(aff)
    {
        printf("%s\n",aff->path_env);
        aff = aff->next_env;
    }
    
}

int main(int argc,char **argv, char **env)
{
    t_env *envv = ft_env(env);
    ft_export_var(&envv,argv);
    return 0;
}