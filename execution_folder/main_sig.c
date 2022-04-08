/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:56:17 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/08 12:08:19 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../parsing_folder/exec_test.h"
// #include "../parsing_folder/minishell.h"

// void handler(int sig)
// {
//     char *str;
//     if(sig == SIGINT)
//     {
//         rl_on_new_line();
//         write(1,"\n",1);
//         rl_redisplay();
//         rl_replace_line("",0);
//     }
//         else if (sig == SIGQUIT)
//         {
//             str = readline("ENTRER somthing :");
//              if(!str)
//         {
//             write(1,"exit",4);
//             exit(1);
//         }
//         }
// }

// void line(void)
// {
//       while(1)
//     {
//         char *str = readline("ENTRER somthing :");
//         if(!str)
//         {
//             write(1,"exit",4);
//             exit(1);
//         }     
//     }
// }

// int main(void)
// {
//     int j = 1;
//     struct sigaction sa;
//     struct sigaction act;
//     sa.sa_handler = handler;
//     sigemptyset(&sa.sa_mask);
//     sa.sa_flags = 0;
//     sigaction(SIGINT, &sa , NULL);
//     sigaction(SIGQUIT, &sa , NULL);
//     line();
// }