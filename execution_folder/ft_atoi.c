/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:33:38 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/31 11:12:54 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

static int	ft_range(const char *chr, int sign)
{
	int				index;
	unsigned long	ret;

	ret = 0;
	index = 0;
	if (chr[index] == '\0')
		return (0);
	while (ft_isdigit(chr[index]))
	{
		ret = (ret * 10) + (chr[index] - '0');
		index++;
	}
	if (ret > 9223372036854775807 && sign > 0)
		return (-1);
	if (ret > 9223372036854775807 && sign < 0)
		return (0);
	return (ret);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	result = ft_range(&nptr[i], sign);
	return (result * sign);
}
