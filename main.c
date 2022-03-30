#include "minishell.h"
//EXEC
#include "exec_test.h"
//EXEC

int	main(int argc, char *argv[], char **env)
{
	char	*input;
	char	**input_split;
	t_env	*env_var;
	t_cmd	*commands;
	
	commands = NULL;
	env_var = ft_env(env);
	while (1)
	{
		take_input(&input);
		//Signal
		if (check_errors(input))
		{
			input_split = split_input(input);
			check_env(input, input_split, env_var);
			commands = parse_everything(input_split, count_words(input));
			//execute
		}
		t_cmd	*tmp;
		int	i = -1;
		tmp = commands;
		while (tmp != NULL)
		{
			printf("Nb here_doc : %d\n", tmp->how_many_here_doc);
			while (tmp->limiters != NULL && tmp->limiters[++i])
				printf("Limiter %d is : %s\n", i, tmp->limiters[i]);
			printf("Infile is : %d\n", tmp->in_file_op);
			printf("Outfile is : %d\n", tmp->out_file_op);
			i = -1;
			while (tmp->cmd_w_arg != NULL && tmp->cmd_w_arg[++i])
				printf("Arg %d is %s\n", i, tmp->cmd_w_arg[i]);
			tmp = tmp->next;
		}
	}
}
