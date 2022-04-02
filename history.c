/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:30:18 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/02 15:30:19 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	history_check(void)
{
	int		fd;
	char	*line;

	fd = open(".his", O_CREAT | O_RDONLY, 0644);
	line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		add_history(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	add_h(char *input)
{
	int	fd;

	fd = open(".his", O_CREAT | O_WRONLY | O_APPEND, 0644);
	add_history(input);
	write(fd, input, le(input));
	write(fd, "\n", 1);
	close(fd);
}
