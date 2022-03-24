#ifndef EXEC_TEST_H
# define EXEC_TEST_H

//EXECUTION
typedef struct t_envir
{
    char *path_env;
    struct t_envir *next_env;
}t_env;
t_env	*ft_env(char **envi);
t_env	*bring_last(t_env *father_of_env);
void	create_env(t_env **envv, char *path_env);
char	*search_in_env(t_env **envv, char *your_var);
//EXECUTION

#endif
