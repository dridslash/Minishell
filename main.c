/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:04:51 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/02 13:07:51 by oessayeg         ###   ########.fr       */
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

	commands = NULL;
	env_var = ft_env(env);
	while (1)
	{
		take_input(&input);
		//Signals here
		if (check_errors(input))
		{
			input_split = split_input(input);
			check_env(input, input_split, env_var);
			commands = parse_everything(input_split, count_words(input));
			print_struct(commands);
			free_all(input_split, input, count_words(input), commands);
			//Execution here
			//printf("\n\n\nLEAKS HERE\n\n\n");
			//system("leaks a.out");
		}
	}
}
