/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:47:04 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/08 14:29:28 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_after_nl(char *buff)
{
	char	*string;
	int		c;

	c = 0;
	while (buff[c] != '\0' && buff[c] != '\n')
		c++;
	if (buff[c] == '\0' || (buff[c] == '\n' && buff[c + 1] == '\0'))
	{
		ft_zero(buff);
		return ;
	}	
	c++;
	string = ft_strdup_parsing(&buff[c]);
	if (!string)
		return ;
	ft_zero(buff);
	c = 0;
	while (string[c] != '\0')
	{
		buff[c] = string[c];
		c++;
	}
	buff[c] = '\0';
	free (string);
}

void	ft_zero(char *buff)
{
	int	compteur;

	compteur = 0;
	while (buff[compteur] != '\0')
	{
		buff[compteur] = '\0';
		compteur++;
	}
}

char	*join_and_free(char *str, char *buffer)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(tmp, buffer);
	if (tmp)
		free(tmp);
	return (str);
}

char	*read_file(int fd)
{
	int			last_byte;
	static char	buffer[BUFFER_SIZE + 1];
	char		*ret_string;

	ret_string = NULL;
	if (check_nl(buffer) == 1)
		return (get_before_nl(buffer, 1));
	if (buffer[0] != '\0')
		ret_string = ft_strjoin(ret_string, buffer);
	ft_zero(buffer);
	last_byte = read(fd, buffer, BUFFER_SIZE);
	while (last_byte > 0)
	{
		ret_string = join_and_free(ret_string, buffer);
		if (check_nl(buffer) == 1)
		{
			get_after_nl(buffer);
			break ;
		}
		ft_zero(buffer);
		last_byte = read(fd, buffer, BUFFER_SIZE);
	}
	return (ret_string);
}

char	*get_next_line(int fd)
{
	char	*s;

	s = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 0 || read(fd, s, 0) < 0)
		return (NULL);
	s = read_file(fd);
	if (s == NULL)
		return (NULL);
	return (get_without_nl(s));
}
