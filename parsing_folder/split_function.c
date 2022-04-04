/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:40:30 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/04 19:57:52 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	coun(char *st, char deli)
{
	int	count;
	int	compteur;

	if (!st)
		return (0);
	compteur = 0;
	count = 0;
	while (st[compteur] != '\0')
	{
		if (compteur == 0 && st[compteur] != deli)
			count++;
		else if (st[compteur] != deli && st[compteur - 1] == deli)
			count++;
		compteur++;
	}
	return (count);
}

int	*len_of_w(char *my_string, char dtr)
{
	int	n;
	int	*array_of_sizes;
	int	index;

	index = 0;
	n = 0;
	array_of_sizes = ft_calloc(coun(my_string, dtr));
	if (!array_of_sizes)
		return (0);
	while (my_string[n] == dtr)
		n++;
	while (my_string[n] != '\0')
	{
		if (my_string[n] != dtr)
			array_of_sizes[index]++;
		else if (my_string[n] == dtr && my_string[n + 1] != dtr)
		{
			array_of_sizes[index]++;
			index++;
		}
		n++;
	}
	array_of_sizes[index]++;
	return (array_of_sizes);
}

char	**copy_strings(char **re_string, char *strii, char dm, int n)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	while (strii[n] != '\0')
	{
		if (strii[n] != dm)
		{
			re_string[i1][i2] = strii[n];
			i2++;
		}
		else if ((strii[n] == dm && strii[n + 1] != dm)
			|| strii[n + 1] == '\0')
		{
			re_string[i1][i2] = '\0';
			i2 = 0;
			i1++;
		}
		n++;
	}
	return (re_string);
}

int	give_index(char *sttt, char ddd)
{
	int	lo;

	lo = 0;
	while (sttt[lo] == ddd && sttt[lo] != '\0')
		lo++;
	return (lo);
}

char	**ft_split_parsing(char *s, char d)
{
	char	**return_string;
	int		*sizes_in_arr;
	int		com;
	int		m;

	if (!s)
		return (NULL);
	m = 0;
	com = 0;
	sizes_in_arr = len_of_w(s, d);
	return_string = (char **)malloc(sizeof(char *) * (coun(s, d) + 1));
	if (!(return_string))
		return (NULL);
	while (com < coun(s, d))
	{
		return_string[com] = (char *)malloc(sizeof(char) * sizes_in_arr[com]);
		if (!return_string[com])
			return (NULL);
		com++;
	}
	return_string[com] = NULL;
	m = give_index(s, d);
	return_string = copy_strings(return_string, s, d, m);
	free(sizes_in_arr);
	return (return_string);
}
