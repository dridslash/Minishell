/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_imp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:22:42 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 10:15:55 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../parsing_folder/exec_test.h"
// #include "../parsing_folder/minishell.h"


// void ft_unset(t_env **env_var,t_cmd *cmd)
// {
//     t_env *looper = (*env_var);
//     t_env *prev;
//     t_env *this;
//     int index = 0;
//     char *holder;
//     int index_var;
//     t_env *tmp;
//     if(cmd->cmd_w_arg[index] != NULL && (ft_strcmp(cmd->cmd_w_arg[index],"unset") == 0))
//     {
//         if(cmd->cmd_w_arg[index + 1] != NULL)
//         {
//             holder = get_name_of_env_var(cmd->cmd_w_arg[index + 1]);
//             index_var = get_index_of_env_var(env_var, cmd->cmd_w_arg[index + 1]);
//     while(looper != NULL)
//     {
//         if(ft_strcmp(get_name_of_env_var(looper->path_env),holder) == 0)
//         {
//             if(get_index_of_env_var(env_var,looper->path_env) == 0)
//             {
//                 this = looper->next_env;
//                 (*env_var) = this;
//                 looper->next_env = NULL;
//                 free(looper);
//                 break;
//             }
//             else
//             {
//                 tmp = looper;
//                 prev->next_env = tmp->next_env;
//                 tmp->next_env = NULL;
//                 free(tmp);
//             }
//         }
//         prev = looper;
//         looper = looper->next_env;
//     }
//         }
//         else
//         {}
//     }
//     else
//     printf("where is the unset !!! dooo ittt !!!\n");
    
// }

// void ft_exit(int argc, char **argv)
// {
//     int index_tmp = 1;
//     int status = 0;
//     if(argv[index_tmp] != NULL && (ft_strcmp(argv[index_tmp], "exit") == 0))
//     {
//         if(argv[index_tmp + 1] != NULL)
//         {
//             status = ft_atoi(argv[index_tmp + 1]);
//             exit(status);
//         }
//         else
//         exit(0);
//     }
//     else
//     printf("you wanna exit without exit go go go !!!\n");
// }

// int main(int argc,char **argv, char **env)
// {
//     t_env *envv = ft_env(env);
//    ft_export_var(&envv,argv);
//    t_env *aff = (envv);
//     // while(aff)
//     //     {
//     //              printf("%s\n",aff->path_env);
//     //              aff = aff->next_env;
//     //     }
//     //t_env *aff  = envv;
//     // while(aff)
//     // {
//     //     printf("%s\n",aff->path_env);
//     //     aff = aff->next_env;
//     // }
//     // printf("\n----------------------------------------------------------------\n");
//     // while(aff)
//     //             {
//     //              printf("%s\n",aff->path_env);
//     //              aff = aff->next_env;
//     //             }
//     // printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
//     // ft_unset(&envv,argv);
//     //aff = envv;
//     // printf("\n----------------------------------------------------------------\n");
//     // while(aff)
//     //             {
//     //              printf("%s\n",aff->path_env);
//     //              aff = aff->next_env;
//     //             }
//     // printf("\n----------------------------------------------------------------\n");
//     //ft_exit(argc,argv);
//     return 0;
// }