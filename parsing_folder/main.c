/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:21:58 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 19:53:39 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//EXEC
#include "exec_test.h"
//EXEC
void	print_struct(t_cmd *com)
{
	int	i;

	while (com != NULL)
	{
		i = 0;
		printf("How many here_docs : %d\n", com->how_many_here_doc);
		if (com->limiters != NULL)
		{
			while (com->limiters[i] != NULL)
			{
				printf("Limiter %d is %s\n", i, com->limiters[i]);
				i++;
			}
		}
		printf("Infile is %d\n", com->in_file_op);
		printf("Outfile is %d\n", com->out_file_op);
		i = 0;
		if (com->cmd_w_arg != NULL)
		{
			while (com->cmd_w_arg[i])
			{
				printf("Arg %d is %s\n", i, com->cmd_w_arg[i]);
				i++;
			}
		}
		com = com->next;
		printf("-------------------\n");
	}
}

int	main(int argc, char *argv[], char **env)
{
	char	*input;
	char	**input_split;
	t_env	*env_var;
	t_cmd	*commands;

	(void)argv;
	(void)argc;
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
			// print_struct(commands);
			//built_ins
			ft_echo(commands);
			// ft_unset(&env_var,commands);
			// ft_export_var(commands,&env_var);
			// if(ft_strcmp(commands->cmd_w_arg[0],"env") == 0)
			// env_show(commands,env_var);
			ft_cd(commands, env_var);
			// ft_exit(commands);
			ft_pwd(commands, env_var);
			//execute
			//main_execution_func(commands, env_var);
			//free_after_exectuion
			free_all(input_split, input, count_words(input), commands);
			system("leaks minishell");
		}
	}
}
