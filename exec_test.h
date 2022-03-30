#ifndef EXEC_TEST_H
# define EXEC_TEST_H

//EXECUTION
typedef struct t_envir
{
    char *path_env;
    struct t_envir *next_env;
}t_env;

typedef struct t_command
{
	char				*here_doc_char;
	char				**limiters;
	int					how_many_here_doc;
    int					in_file_op;
    int					out_file_op;
    char				**cmd_w_arg;
    struct t_command	*next;
}t_cmd;

t_env	*ft_env(char **envi);
t_env	*bring_last(t_env *father_of_env);
void	create_env(t_env **envv, char *path_env);
char	*search_in_env(t_env **envv, char *your_var);
int		ft_strcmp(char *s1, char *s2);
char	*get_name_of_env_var(char *tb);
char	*get_after_equal(char *your_path);
int		ft_strlen(char *s);
char	*get_after_dollar(char *your_path);
//EXECUTION
//test
char *search_test(t_env **envv, char *your_var);

//test
#endif
