/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:46:42 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/09 18:03:24 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *string)
{
	int	compteur;

	compteur = 0;
	while (string[compteur] != '\0')
	{
		if (string[compteur] == '\n')
			return (compteur + 1);
		compteur++;
	}
	return (compteur);
}

int	check_nl(char *string)
{
	int	compteur;

	if (string == NULL)
		return (0);
	compteur = 0;
	while (string[compteur] != '\0')
	{
		if (string[compteur] == '\n')
			return (1);
		compteur++;
	}
	return (0);
}

char	*ft_strdup_parsing(char *string)
{
	char	*return_string;
	int		compteur;

	compteur = 0;
	while (string[compteur] != '\0')
		compteur++;
	return_string = malloc(sizeof(char) * (compteur + 1));
	if (!return_string)
		return (NULL);
	compteur = 0;
	while (string[compteur] != '\0')
	{
		return_string[compteur] = string[compteur];
		compteur++;
	}
	return_string[compteur] = '\0';
	return (return_string);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*return_string;
	int		compteur1;
	int		compteur2;

	if (s1 && !s2)
		return (ft_strdup_parsing(s1));
	else if (!s1 && s2)
		return (get_before_nl(s2, 0));
	return_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!return_string)
		return (NULL);
	compteur1 = -1;
	while (s1[++compteur1] != '\0')
		return_string[compteur1] = s1[compteur1];
	compteur2 = -1;
	compteur1--;
	while (s2[++compteur2] != '\0' && s2[compteur2] != '\n')
		return_string[++compteur1] = s2[compteur2];
	if (s2[compteur2] == '\n')
		return_string[++compteur1] = '\n';
	return_string[++compteur1] = '\0';
	return (return_string);
}

char	*get_before_nl(char *buffer, int option)
{
	int		compteur;
	char	*return_string;

	compteur = ft_strlen(buffer);
	return_string = malloc(sizeof(char) * (compteur + 1));
	if (!return_string)
		return (NULL);
	compteur = 0;
	while (buffer[compteur] != '\n' && buffer[compteur] != '\0')
	{
		return_string[compteur] = buffer[compteur];
		compteur++;
	}
	if (buffer[compteur] == '\n')
	{
		return_string[compteur] = '\n';
		compteur++;
	}
	return_string[compteur] = '\0';
	if (option == 1)
		get_after_nl(buffer);
	return (return_string);
}
