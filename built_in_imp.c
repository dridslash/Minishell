/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_imp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:22:42 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/25 17:04:49 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h" 

void ft_pwd(int argc , char **argv)
{
    int index_tmp=1;
    if((argv[index_tmp] != NULL) && (ft_strcmp(argv[index_tmp], "pwd") == 0))
    {
    char current_dir[FILE_N_MAX];
    current_dir[FILE_N_MAX - 1] = '\0';
    getcwd(current_dir,FILE_N_MAX);
    printf("%s\n",current_dir);
    }
    else
    printf("print pwd or im not showing you the current dir -- hint ;)");
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
          if(ft_strcmp(argv[index_tmp + 1],"~") == 0)
          {
              if(chdir(get_home))
                 perror(">>shell : cd ");
          }
          else
          {
        if(chdir(argv[index_tmp + 1]) != 0)
         perror(">>shell : cd ");
          }
     }
     else
     chdir(get_home);
     }
     else
     {
         if(chdir(argv[index_tmp]) != 0)
         perror(">>shell : cd ");
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
    return (main_env);
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

char *get_after_equal(char *your_path)
{
    int  i =0;
    while(your_path[i])
    {
        if(your_path[i] == '=')
        {
            return (&your_path[i + 1]);
        }
        i++;
    }
    return (NULL);
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
        if(chr[i] == '=' || (chr[i] == '+' && chr[i + 1] == '='))
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

void part_two_of_export(t_env **envv, char **argv, int index_tmp)
{
    int i = 0;
    char *holder = argv[index_tmp + 1];
    char *joined;
    int found = 1;
     t_env *iterta = (*envv);
     t_env *aff = (*envv);
     while(iterta)
     {
         if(ft_strcmp(get_name_of_env_var(iterta->path_env),get_name_of_env_var(holder)) == 0)
         {
            iterta->path_env = ft_strjoin_non_free(iterta->path_env,get_after_equal(holder));
            found = 0;
             break;
         }
         iterta = iterta->next_env;
     }
       if (found == 1)
         {
             joined = get_name_of_env_var(holder);
             joined = ft_strjoin_non_free(joined,"=");
             joined = ft_strjoin_non_free(joined,get_after_equal(holder));
             create_env(envv,joined);
             return;
         }
}

int check_for_minus(char *your_path)
{
    int i =0;
    while(your_path[i])
    {
            if(your_path[i] == '-' && (i < get_equal_index(your_path)))
             {
               return (1);  
             }
             i++;
    }
    return (0);
}
int check_for_plus(char *your_path)
{
    int i =0;
    while(your_path[i])
    {
            if(your_path[i] == '+' && your_path[i + 1] != '=')
             {
               return (2);  
             }
             i++;
    }
    return (0);
}

int check_for_plus_to_export(char *your_path)
{
    int i =0;
    while(your_path[i])
    {
            if(your_path[i] == '+' && your_path[i + 1] == '=')
             {
               return (8);  
             }
             i++;
    }
    return (0);
}


int check_for_digits(char *your_path)
{
    int i =0;
    while(your_path[i])
    {
            if(ft_isdigit(your_path[i]) && i == 0)
             {
               return (3);  
             }
             i++;
    }
    return (0);
}

int check_for_space(char *your_path)
{
     int i = 0;
    while(your_path[i])
    {
            if(your_path[i] == ' ' && i > get_equal_index(your_path))
             {
               return (7);
             }
             else if (your_path[i] == ' ' && i < get_equal_index(your_path))
             {
                 return (4);
             }
             i++;
    }
    return (0);
}

int check_simple_quote(char *your_path)
{
    int i = 0;
    while(your_path[i])
    {
        if(your_path[i] == '\'')
        {
            return (10);
        }
        i++;
    }
    return (0);
}

int check_empty_path_name(char *your_path)
{
    if(get_equal_index(your_path) == 0)
    {
        return (9);
    }
    return (0);
}

char *get_after_dollar(char *your_path)
{
    int  i =0;
    while(your_path[i])
    {
        if(your_path[i] == '$')
        {
            return (&your_path[i + 1]);
        }
        i++;
    }
    return (NULL);
}


char *search_in_env(t_env **envv,char * your_var)
{
    t_env *aff = (*envv);
    while(aff)
             {
                 if(ft_strcmp(get_name_of_env_var(aff->path_env),get_name_of_env_var(your_var)) == 0)
                 {
                     return(get_after_equal(aff->path_env));
                 }
                 aff = aff->next_env;
             }
    return (ft_strdup(""));
}

void handle_dollar_export(t_env **envv,char **argv,int index_tmp)
{
            
     int i =0;
    int locker = 0;
    t_env *aff = (*envv);
    char *holder = argv[index_tmp + 1];
    char *holder_try = ft_strdup("$hellofwfw=pl");
    char **big_boy;
    char *value_dollar;
    if(argv[index_tmp + 1] != NULL && get_equal_index(argv[index_tmp + 1]) != -1)
         {
             if(search_in_env(envv,get_after_dollar(holder_try)) == NULL)
             {
                 printf("go away $ in first we are not that rich !!\n");
             }
             else
             {
            value_dollar = search_in_env(envv,get_after_dollar(holder_try));
            printf("%s\n",value_dollar);
            big_boy = ft_split(holder_try,'$');
            big_boy[0] = ft_strjoin(big_boy[0],value_dollar);
            big_boy[0] = ft_strjoin(big_boy[0],"=");
            big_boy[0] = ft_strjoin(big_boy[0],get_after_equal(holder_try));
            create_env(envv,big_boy[0]);
             while(aff)
                {
                 printf("%s\n",aff->path_env);
                 aff = aff->next_env;
                }
             }
         }
         else
         {
             printf("insert an equal or go away man !!");
         }
}

int check_if_there_is_a_dollar(char * your_path)
{
    int i = 0;
    while(your_path[i])
    {
        if (your_path[i] == '$')
        return (1);
        i++;
    }
    return (0);
}

int check_is_exportable(char *your_path)
{
    int i = 0;
    while(your_path[i] != '=')
    {
        if(ft_isascii(your_path[i]))
        {
            if((ft_isdigit(your_path[i]) == 0) && (ft_isalpha(your_path[i]) == 0) && (your_path[i] != '='))
            {
                if (your_path[i] == '+' && (your_path[i + 1] == '='))
                return (0);
                else
                return (11);
            }
        }
        i++;
    }
    return (0);
}

int check_errors(char *your_path)
{
    int i = 0;
     i = check_simple_quote(your_path);
    if(i > 0)
    return (i);
     i = check_empty_path_name(your_path);
    if(i > 0)
    return (i);
    i = check_for_space(your_path);
    if(i > 0)
    return (i);
    i = check_for_digits(your_path);
    if(i > 0)
    return (i);
    i = check_for_minus(your_path);
    if(i > 0)
    return (i);
    i = check_for_plus(your_path);
    return (i);
}

void display_sorted_env_vars(t_env **envv)
{
    t_env *aff;
    aff =(*envv);
    sort_alpha(envv);
}

void ft_export_var(t_env **envv,char **argv)
{
    int i =0;
    int equal_sing_her = 0;
    int index_tmp = 1;
    char *holder = argv[index_tmp + 1];
    char *trimed;
    if(ft_strcmp(argv[index_tmp],"export") == 0)
     {
         if(argv[index_tmp + 1] != NULL)
         {
         if (check_errors(holder) == 2)
         {
               printf("really + without an = go out !! \n");
               return;
         }
        if (check_errors(holder) == 1)
         {
              printf("minus no no no !! \n");
               return;
         }
         if (check_errors(holder) == 3)
         {
              printf("digit error no no no !! \n");
               return;
         }
         if (check_errors(holder) == 7)
         {
             trimed = get_name_of_env_var(holder);
             trimed = ft_strjoin_non_free(trimed,"=");
            create_env(envv,trimed);
            t_env *aff = (*envv);
            while(aff)
                {
                 printf("%s\n",aff->path_env);
                 aff = aff->next_env;
                } 
               return;
         }
         if (check_errors(holder) == 4)
         {
              printf("space error no no no !! \n");
               return;
         }
         if (check_errors(holder) == 9)
         {
             printf("i handeled the no name env go away zsh !!\n");
             return;
         }
         if (check_errors(holder) == 10)
         {
             printf("i handeled single quote problem ho ho !!\n");
             return;
         }
         if (check_is_exportable(holder) == 11)
         {
             printf("i handeled ascii go away zsh !!\n");
             return;
         }
         if (check_for_plus_to_export(holder) == 8)
         {
             part_two_of_export(envv,argv,index_tmp);
             return;
         }
         if (check_if_there_is_a_dollar(holder) == 1)
         {
         handle_dollar_export(envv,argv,index_tmp);
         return;
         }
         else
         {
         part_one_of_export(envv,argv,index_tmp);
         return;
         }
         }
         else
         {
             display_sorted_env_vars(envv);
         }
     }
}

int get_index_of_env_var(t_env **envv,char * your_path)
{
    int index = 0;
    t_env *tmp = (*envv);
    while(tmp)
    {
        if(ft_strcmp(get_name_of_env_var(tmp->path_env) , get_name_of_env_var(your_path)) == 0)
        {
            return (index);
        }
        index++;
        tmp = tmp->next_env;
    }
    return (-1);
}

void ft_unset(t_env **envv,char **argv)
{
    t_env *looper = (*envv);
    t_env *prev;
    t_env *this;
    int index_tmp = 1;
    char *holder;
    int index_var;
    t_env *tmp;
    if(argv[index_tmp] != NULL && (ft_strcmp(argv[index_tmp],"unset") == 0))
    {
        if(argv[index_tmp + 1] != NULL)
        {
            holder = get_name_of_env_var(argv[index_tmp + 1]);
            index_var = get_index_of_env_var(envv, argv[index_tmp + 1]);
    while(looper != NULL)
    {
        if(ft_strcmp(get_name_of_env_var(looper->path_env),holder) == 0)
        {
            if(get_index_of_env_var(envv,looper->path_env) == 0)
            {
                this = looper->next_env;
                (*envv) = this;
                looper->next_env = NULL;
                free(looper);
                break;
            }
            else
            {
                tmp = looper;
                prev->next_env = tmp->next_env;
                tmp->next_env = NULL;
                free(tmp);
            }
        }
        prev = looper;
        looper = looper->next_env;
    }
        }
        else
        {}
    }
    else
    printf("where is the unset !!! dooo ittt !!!\n");
    
}

void ft_exit(int argc, char **argv)
{
    int index_tmp = 1;
    int status = 0;
    if(argv[index_tmp] != NULL && (ft_strcmp(argv[index_tmp], "exit") == 0))
    {
        if(argv[index_tmp + 1] != NULL)
        {
            status = ft_atoi(argv[index_tmp + 1]);
            exit(status);
        }
        else
        exit(0);
    }
    else
    printf("you wanna exit without exit go go go !!!\n");
}

int main(int argc,char **argv, char **env)
{
    t_env *envv = ft_env(env);
   ft_export_var(&envv,argv);
   t_env *aff = (envv);
    // while(aff)
    //     {
    //              printf("%s\n",aff->path_env);
    //              aff = aff->next_env;
    //     }
    //t_env *aff  = envv;
    // while(aff)
    // {
    //     printf("%s\n",aff->path_env);
    //     aff = aff->next_env;
    // }
    // printf("\n----------------------------------------------------------------\n");
    // while(aff)
    //             {
    //              printf("%s\n",aff->path_env);
    //              aff = aff->next_env;
    //             }
    // printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    // ft_unset(&envv,argv);
    //aff = envv;
    // printf("\n----------------------------------------------------------------\n");
    // while(aff)
    //             {
    //              printf("%s\n",aff->path_env);
    //              aff = aff->next_env;
    //             }
    // printf("\n----------------------------------------------------------------\n");
    //ft_exit(argc,argv);
    return 0;
}