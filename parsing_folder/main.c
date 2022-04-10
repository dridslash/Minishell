/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:21:58 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/10 10:07:05 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//EXEC
#include "exec_test.h"
//EXEC
int exit_status = 50;
// void	print_struct(t_cmd *com)
// {
// 	int	i;

// 	while (com != NULL)
// 	{
// 		i = 0;
// 		printf("How many here_docs : %d\n", com->how_many_here_doc);
// 		if (com->limiters != NULL)
// 		{
// 			while (com->limiters[i] != NULL)
// 			{
// 				printf("Limiter %d is %s\n", i, com->limiters[i]);
// 				i++;
// 			}
// 		}
// 		printf("Infile is %d\n", com->in_file_op);
// 		printf("Outfile is %d\n", com->out_file_op);
// 		i = 0;
// 		if (com->cmd_w_arg == NULL)
// 		{
// 			printf("it is NULL");
// 			// while (com->cmd_w_arg[i])
// 			// {
// 			// 	printf("Arg %d is %s\n", i, com->cmd_w_arg[i]);
// 			// 	i++;
// 			// }
// 		}
// 		com = com->next;
// 		printf("-------------------\n");
// 	}
// }

void handler(int sig)
{
    char *str;
    if(sig == SIGINT)
    {
		rl_replace_line("",0);
        rl_on_new_line();
        write(1,"\n",1);
        rl_redisplay();
        rl_replace_line("",0);
    }
        else if (sig == SIGQUIT)
        {
			rl_on_new_line();
			rl_redisplay();
        }
}

void signal_main(char **input)
{
    struct sigaction sa;
    struct sigaction act;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa , NULL);
    sigaction(SIGQUIT, &sa , NULL);
	take_input(input);
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
	history_check();
	while (1)
	{
		//Signal
		signal_main(&input);
		//END OF SIGNALS
		if (check_errors(input))
		{
			//parse_commands
			//printf("Id is %d\n", getpid());
			input_split = split_input(input);
			check_env(input, input_split, env_var);
			commands = parse_everything(input_split, count_words(input));
			if ((commands->cmd_w_arg != NULL && ft_strcmp(commands->cmd_w_arg[0],"exit") == 0) && count_size_of_list(commands) == 1)
				ft_exit(commands);
			//execute_commands
			// if (count_size_of_list(commands) == 1)
			// 	env_show(commands, &env_var, 1);
			// 	else
			main_execution_func(commands, env_var);
			printf("exit_status : %d\n",exit_status);
			// free_after_exectuion
			free_all(input_split, input, count_words(input), commands);
			// system(("leaks minishell"));
		}
	}
}
