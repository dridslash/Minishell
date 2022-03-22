/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:09:45 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/22 10:15:45 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int charachter_eater(int argc , char **argv, int is_there_option)
{
    int i = 2;
    int count_is_there = 0;
    while(argv[i])
    {
        if(argv[i] != NULL)
        {
            count_is_there ++;
        }
    }
    return (count_is_there);
}

void ft_echo(int argc, char **argv)
{
    int index_tmp = 1;
    int option_of_echo = index_tmp + 1;
    if(ft_strcmp(argv[index_tmp],"echo") == 0)
    {
        if(argv[option_of_echo] == NULL)
        {
            write(1,"\n",1);
        }
        else if (argv[option_of_echo] != NULL && (ft_strcmp(argv[option_of_echo],"-n") == 0))
        {
            write(1,"",1);
        }
    }
}
int main(int argc, char **argv)
{
    ft_echo(argc,argv);
    // charachter_eater(argc, argv);
}