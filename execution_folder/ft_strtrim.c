/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:53:39 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 17:35:58 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

static int	is_set(char s1, char const *set)
{
	char	com;
	int		i;

	com = s1;
	i = 0;
	while (set[i] != '\0')
	{
		if (com == set[i])
		{
			return (1);
		}
		i++;
	}	
	return (0);
}

static int	ft_pos(char const *s1, char const *set)
{
	size_t	pos;
	size_t	i;

	pos = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (is_set(s1[i], set))
		{
			pos++;
		}
		else
			return (pos);
		i++;
	}
	return (pos);
}

char	*ft_strtrim(char	*s1, char	*set)
{
	char	*tr;
	int		pos;
	int		i;
	int		k;

	if (!s1)
		return (NULL);
	pos = ft_pos(s1, set);
	k = ft_strlen(s1);
	i = 0;
	while (i < k && is_set((char)s1[k - 1], set))
	{
		k--;
	}	
	if (k > pos)
		tr = (char *)malloc(sizeof(char) * (k - pos + 1));
	else
		tr = (char *)malloc(sizeof(char));
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (pos < k)
		tr[i++] = s1[pos++];
	tr[i] = '\0';
	return (tr);
}
