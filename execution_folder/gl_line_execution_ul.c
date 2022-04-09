/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_line_execution_ul.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:57:18 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/09 15:23:21 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

char	*ft_substr(char	*s, unsigned int start, int len)
{
	char			*sub;
	unsigned int	index;
	int				l;	

	l = len;
	if (s == NULL)
		return (NULL);
	if ((int)start >= ft_strlen(s))
		return (ft_strdup_execution(""));
	if (len > ft_strlen(s))
		l = ft_strlen(s);
	sub = (char *)malloc((l + 1) * sizeof(char));
	if (sub == NULL)
	{
		return (NULL);
	}
	index = 0;
	while ((int)index < l)
	{
		sub[index] = s[start];
		index++;
		start++;
	}
	sub[index] = '\0';
	return (sub);
}

int	ft_strchr(char *s, int c)
{
	int			i;
	int			l;

	i = 0;
	l = ft_strlen(s);
	while (i <= l)
	{
		if (s[i] == (unsigned char)c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
