/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_non_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:35:34 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 17:33:38 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

char	*ft_strjoin_non_free(char	*s1, char	*s2)
{
	int		i;
	int		res;
	char	*clon;

	if (!s1 || !s2)
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
	clon[i] = '\0';
	return (clon);
}
