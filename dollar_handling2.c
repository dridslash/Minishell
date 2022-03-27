#include "minishell.h"

void	get_single_q_dollar(char *input, int *i1, char **string)
{
	(*i1)++;
	while (input[*i1] != '\'')
	{
		*string = char_join(*string, input[*i1]);
		(*i1)++;
	}
}

void	get_after_q2(char *input, int *i1, char **string, t_env *env)
{
	char	*s;
	char	*t;

	s = NULL;
	while (input[*i1] != '\"')
	{
		s = char_join(s, input[*i1]);
		(*i1)++;
	}
	(*i1)--;
	t = s;
	//s = search_in_env(&env, s + 1);
	//test
	s = search_in_env1(env, s);
	printf("%s\n", s);
	//end test
	free(t);
	if (s == NULL)
		return ;
	*string = t_strjoin(*string, s);
}
