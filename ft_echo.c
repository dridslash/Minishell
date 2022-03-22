/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:09:45 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/22 12:13:32 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int charachter_eater(int argc , char ** argv,int is_there_stopper_newline, int start)
{
    int i = 0;
    i = start;
    if(is_there_stopper_newline == 1)
    i++;
    int count_if_there_an_arg = 0;
    while(argv[i])
    {
        if(argv[i] != NULL)
        {
            count_if_there_an_arg++;
        }
        i++;
    }
    return (count_if_there_an_arg);
}

void ft_echo(int argc, char **argv)
{
    int index_tmp = 1;
    int option_of_echo = index_tmp + 1;
    int args = 0;
    if(argv[index_tmp] != NULL && (ft_strcmp(argv[index_tmp], "echo") == 0))
    {
        if(argv[option_of_echo] != NULL)
        {
        if(ft_strcmp(argv[option_of_echo],"-n") != 0)
        {
           if(charachter_eater(argc,argv,0,option_of_echo) > 0)
           {
               args = option_of_echo;
               while(argv[args])
               {
                   write(1,argv[args],ft_strlen(argv[args]));
                   args++;
               }
               write(1,"\n",1);
           }
        }
        else
        {
           if(charachter_eater(argc,argv,1,option_of_echo) > 0)
           {
               args = option_of_echo + 1;
               while(argv[args])
               {
                   write(1,argv[args],ft_strlen(argv[args]));
                   args++;
               }
           }
           else
           write(1,"",1);
        }
        }
        else
        {
            write(1,"\n",1);
        }
    }
    else
    printf("there is no echo - echo - echo \n");
}
int main(int argc, char **argv)
{
    ft_echo(argc,argv);
    // charachter_eater(argc, argv);
}