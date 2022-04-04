/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:21:58 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 15:38:51 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			//built_ins
			ft_echo(commands);
			// ft_unset(&env_var,commands);
			// ft_export_var(commands,&env_var);
			// if(ft_strcmp(commands->cmd_w_arg[0],"env") == 0)
			// env_show(commands,env_var);
			// ft_cd(commands, env_var);
			// ft_exit(commands);
			// ft_pwd(commands, env_var);
			//execute
			//main_execution_func(commands, env_var);
		}
	}
}
