/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:18 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/31 11:13:04 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

int	ft_isalpha(int chr)
{
	if ((chr >= 65 && chr <= 90) || (chr >= 97 && chr <= 122))
	{
		return (1);
	}
	return (0);
}
