/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_execution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:46:48 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 17:36:11 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

// static void	ft_free(char **s1, char **s2)
// {
// 	free(*s1);
// 	*s1 = NULL;
// 	free(*s2);
// 	*s2 = NULL;
// }

// static void	ft_freesmall(char **s1)
// {
// 	free(*s1);
// 	*s1 = NULL;
// }

// static void	ft_next(char **buffer, char **sline, char **saver, int fd)
// {
// 	char	*tmp;
// 	ssize_t	holder;

// 	holder = 1;
// 	while (holder && ft_strchr((*saver), '\n') == -1)
// 	{
// 		holder = read(fd, (*buffer), BUFFER_SIZE);
// 		(*buffer)[holder] = '\0';
// 		(*saver) = ft_strjoin((*saver), (*buffer));
// 	}
// 	free(*buffer);
// 	if (holder == 0)
// 	{
// 		(*sline) = ft_strdup_execution(*saver);
// 		ft_freesmall(saver);
// 	}
// 	else
// 	{
// 		(*sline) = ft_substr((*saver), 0, ft_strchr((*saver), '\n') + 1);
// 		tmp = (*saver);
// 		(*saver) = ft_strdup_execution((*saver) + ft_strchr((*saver), '\n') + 1);
// 		free(tmp);
// 	}
// 	if (!(**sline))
// 		ft_free(saver, sline);
// }

// char	*get_next_line_execution(int fd)
// {
// 	static char	*saver;
// 	char		*buffer;
// 	char		*sline;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	if (read(fd, buffer, 0) == -1)
// 	{
// 		free(buffer);
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	if (!saver)
// 		saver = ft_strdup_execution("");
// 	ft_next(&buffer, &sline, &saver, fd);
// 	return (sline);
// }

// int main (void)
// {

//      int fd = open("TEST",O_RDONLY);
//       for(int i=0 ; i < 6;i++)
// 	  get_next_line(fd);

//      return 0;
// }
