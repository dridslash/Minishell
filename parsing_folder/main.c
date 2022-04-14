/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:21:58 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/14 12:31:20 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//EXEC
#include "exec_test.h"
//EXEC
int	g_exit_status = 0;

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		write(1, "\n", 1);
		rl_redisplay();
		rl_replace_line("", 0);
		g_exit_status = 1;
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 0;
	}
}

void	call_signal_try_help(t_cmd *holder_nodes)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	try_help(holder_nodes);
}

void	signal_main(char **input)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	take_input(input);
}

void	in_main(t_cmd **commands, t_env **env_var, char **env)
{
	(*commands) = NULL;
	(*env_var) = ft_env(env);
}

int	main(int argc, char *argv[], char **env)
{
	char	*input;
	char	**input_split;
	t_env	*env_var;
	t_cmd	*commands;

	(void)argv;
	(void)argc;
	in_main(&commands, &env_var, env);
	history_check();
	while (1)
	{
		signal_main(&input);
		if (check_errors(input))
		{
			input_split = split_input(input);
			check_env(input, input_split, env_var);
			commands = parse_everything(input_split, count_words(input));
			main_execution_func(commands, &env_var);
			if ((commands->cmd_w_arg != NULL
					&& ft_strcmp(commands->cmd_w_arg[0], "exit") == 0)
				&& count_size_of_list(commands) == 1)
				ft_exit(commands);
			free_all(input_split, input, count_words(input), commands);
		}
	}
}
