/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:30:12 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 17:29:59 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_without_nl(char *string)
{
	char	*return_string;
	int		i;

	i = 0;
	return_string = malloc(sizeof(char) * ft_strlen(string));
	while (string[i] != '\n')
	{
		return_string[i] = string[i];
		i++;
	}
	return_string[i] = '\0';
	free(string);
	return (return_string);
}
