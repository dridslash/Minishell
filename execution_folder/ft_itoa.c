/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:05:21 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/05 15:11:24 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

static int	ft_numcount(int n)
{
	int				i;
	unsigned int	a;

	i = 0;
	if (n < 0)
	{
		a = n * (-1);
		i++;
	}
	else
	{
		a = n;
	}
	while (a > 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

static char	*ft_helper(char *tab, int n, int i)
{
	unsigned int	num;

	if (!tab)
		return (ft_strdup_execution(""));
		tab[i] = '\0';
		i--;
	if (n == 0)
	{
		tab[0] = '0';
		return (tab);
	}
	if (n < 0)
	{
		tab[0] = '-';
		num = n * (-1);
	}
	else
		num = n;
	while (num > 0)
	{
		tab[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char			*tab;
	int				i;

	i = ft_numcount(n);
	if (n == 0)
	i += 1;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	tab = ft_helper(tab, n, i);
	return (tab);
}
// int main(void)
// {
// 	int n=-11203;
// 	printf("%s\n",ft_itoa(n));
// }