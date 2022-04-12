/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:27:58 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/12 17:29:30 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PARSING

#include "minishell.h"

//EXECUTION

#include "exec_test.h"

void	take_input(char **input)
{
	char	*tmp;
	int		i;

	*input = readline("$> ");
	if (*input == NULL)
	{
		write(1, "exit\n", 5);
		exit(0);
	}
	i = 0;
	while (*input[i] == ' ')
		i++;
	if (*input[i] == '|')
		return ;
	while (pipe_in_end(*input))
	{
		tmp = readline("> ");
		*input = t_strjoin(*input, tmp);
		if (*input == NULL)
			exit(EXIT_FAILURE);
		if (tmp)
			free(tmp);
	}
	add_h(*input);
}

int	pipe_in_end(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '|')
		{
			i++;
			while (input[i] == ' ')
				i++;
			if (input[i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	len(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*t_strjoin(char *s1, char *s2)
{
	char	*ret_string;
	int		i1;
	int		i2;

	if (s1 == NULL)
		return (ft_strdup_parsing(s2));
	ret_string = malloc(sizeof(char) * (len(s1) + len(s2) + 1));
	i1 = 0;
	i2 = 0;
	while (s1[i1] != '\0')
	{
		ret_string[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\0')
	{
		ret_string[i1] = s2[i2];
		i1++;
		i2++;
	}
	ret_string[i1] = '\0';
	free(s1);
	return (ret_string);
}

char	*char_join(char *string, char c)
{
	char	*return_string;
	int		i;

	if (string == NULL)
		return (ft_strdup_parsing(&c));
	i = 0;
	return_string = malloc(sizeof(char) * ft_strlen(string) + 2);
	while (string[i] != '\0')
	{
		return_string[i] = string[i];
		i++;
	}
	return_string[i] = c;
	return_string[i + 1] = '\0';
	free (string);
	return (return_string);
}
