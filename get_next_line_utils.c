/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:48:18 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/09 18:47:46 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		res;
	char	*clon;

	if (!s1)
		return (NULL);
	clon = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	res = 0;
	i = 0;
	if (clon == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		clon[i] = s1[i];
		i++;
	}
	while (s2[res] != '\0')
	{
		clon[i] = s2[res];
		i++;
		res++;
	}
	free((char *)s1);
	clon[i] = '\0';
	return (clon);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	index;
	size_t			l;	

	l = len;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		l = ft_strlen(s);
	sub = (char *)malloc((l + 1) * sizeof(char));
	if (sub == NULL)
	{
		return (NULL);
	}
	index = 0;
	while (index < l)
	{
		sub[index] = s[start];
		index++;
		start++;
	}
	sub[index] = '\0';
	return (sub);
}

int	ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			l;

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

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*t;

	len = 0;
	len = ft_strlen(src);
	t = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (t == NULL)
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		t[i] = src[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
