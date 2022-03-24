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
    return (NULL);
}

int     ft_strcmp(char  *s1,char    *s2)
{
	while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		   s1++;
		      s2++;
	}
	return *s1 - *s2;
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

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	len;
	char	*t;

	len = 0;
	len = ft_strlen(src);
	t = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (t == NULL)
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		t[i] = src[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
char *get_after_dollar(char *your_path)
{
    int  i;

	i = 0;
    while (your_path[i])
    {
        if (your_path[i] == '$')
            return (&your_path[i + 1]);
        i++;
    }
    return (NULL);
}
//EXECUTION
