#include "minishell.h"
#include "exec_test.h"

//EXECUTION
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
//EXECUTION
