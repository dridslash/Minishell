/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:52:58 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/09 14:35:23 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

char	*ft_strdup_execution(char *src)
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
