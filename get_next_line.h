/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:49:46 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/09 14:29:54 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

//main_function

char	*get_next_line(int fd);

//help_functions
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

#endif