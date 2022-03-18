/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:15:54 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/14 14:11:53 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[0])
		{
			k = i;
			while (big[k] == little[j] && k < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
				k++;
				j++;
			}
		}
		i++;
	}
	return (0);
}
