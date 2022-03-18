/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_imp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:22:42 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/18 19:23:01 by mnaqqad          ###   ########.fr       */
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
     else
     {
         if(chdir(argv[index_tmp]) != 0)
         perror("my shell : cd ");
     }
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

void append_env_vr(t_env **envv,char *var)
{
    t_env *tmp;
    tmp = (*envv);
    char **holder_first;
    while(tmp)
    {
        holder_first = ft_split(tmp->path_env,'=');
        if(ft_strcmp(holder_first[0],var) == 0)
        {
            ft_strjoin_non_free(tmp->path_env,var);
            break;
        }
        tmp = tmp->next_env;
    }
}

char *get_name_of_env_var(char *tb)
{
    int  i =0;
    int index_tmp = 2;
    char *chr = ft_strdup(tb);
    while(chr[i])
    {
        if(chr[i] == '=')
        {
        chr[i] = '\0';
        break;
        }
        i++;
    }
    return (chr);
}

void part_one_of_export(t_env **envv,char **argv,int index_tmp)
{
    int i =0;
    int locker = 0;
    t_env *aff = (*envv);
    char *holder = argv[index_tmp + 1];
    if(argv[index_tmp + 1] != NULL && get_equal_index(argv[index_tmp + 1]) != -1)
         {
             while(aff)
             {
                 if(ft_strcmp(get_name_of_env_var(aff->path_env),get_name_of_env_var(holder)) == 0)
                 {
                     aff->path_env = holder;
                     locker ++;
                     break;
                 }
                 aff = aff->next_env;
             }
            if(locker == 0)
                     {
                     create_env(envv,holder);
                     }
                     aff = (*envv);
             while(aff)
                {
                 printf("%s\n",aff->path_env);
                 aff = aff->next_env;
                } 
         }
         else
         {
             printf("insert an equal or go away man !!");
         }
         
}

void ft_export_var(t_env **envv,char **argv)
{
    int i =0;
    int equal_sing_her = 0;
    int index_tmp = 1;
    char *holder = argv[index_tmp + 1];
    if(ft_strcmp(argv[index_tmp],"export") == 0)
     {
         while(holder[i])
         {
             if(holder[i] == '+' && holder[i + 1] != '=')
             {
             printf("really + without an = go out !! \n");
               break;  
             }
             if (/*holder[i] == '-' ||*/ (holder[i] == '-' && holder[i + 1] == '='))
             {
                printf("minus sign no no !! \n");
               break;  
             }
             i++;
         }
         part_one_of_export(envv,argv,index_tmp);
     }
    
}

int main(int argc,char **argv, char **env)
{
    t_env *envv = ft_env(env);
   ft_export_var(&envv,argv);
    // ft_cd(argc , argv);
    return 0;
}