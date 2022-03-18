/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rediredtions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:03:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/16 17:06:26 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void execute_close(int downstream,int upstream,int count_files,int *pipes)
{
    int i = 0;
    dup2(downstream,0);
    dup2(upstream,1);
    while(i < count_files)
    {
        close(pipes[i]);
        i++;
    }
}

void free_resource(char **freeable)
{
    int i =0;
    while(freeable[i])
    {
        free(freeable[i]);
        i++;
    }
    free(freeable);
    freeable = NULL;
}

int main(int argc , char **argv, char **envp)
{
    t_cmd *linked_commnds = malloc(sizeof(t_cmd));

   linked_commnds = NULL;
    int k = 2;
    char **ag;
    ag = NULL;
    int cmds = argc - 3;
    int in_file = 0;
    int out_file = 0;
    int process = cmds;
    int loop_for_pipes = 0;
    int iterat = 0;
    int *pipes = malloc(sizeof(int) * ((cmds - 1) * 2));
    int *pids = malloc(sizeof(int) * process);
    
    while(loop_for_pipes < (cmds - 1) * 2)
    {
        pipe(&pipes[loop_for_pipes]);
        loop_for_pipes+=2;
    }
    loop_for_pipes = 0;
    while(iterat < cmds)
    {
        if(iterat == 0 && iterat + 1 != cmds)
        {
        in_file = open(argv[1],O_RDONLY);
        ag = get_params(k,argv);
        add_cmd(&linked_commnds, in_file, pipes[loop_for_pipes + 1], ag);
        }
        else if(iterat == 0 && iterat + 1 == cmds)
        {
            in_file = open(argv[1],O_RDONLY);
             ag = get_params(k,argv);
            out_file = open(argv[argc - 1],O_RDWR | O_TRUNC | O_CREAT ,0777);
            add_cmd(&linked_commnds,in_file, out_file, ag);
        }
        else if(iterat + 1 == cmds)
        {
            ag = get_params(k,argv);
            out_file = open(argv[argc - 1],O_RDWR | O_TRUNC | O_CREAT ,0777);
            add_cmd(&linked_commnds, pipes[loop_for_pipes - 2], out_file, ag);
        }
        else
        {
        ag = get_params(k,argv);
         add_cmd(&linked_commnds, pipes[loop_for_pipes - 2], pipes[loop_for_pipes + 1], ag);
        }
        iterat++;
        k++;
        loop_for_pipes +=2;
    }
    int i = 0;
    while (i < process && linked_commnds != NULL)
    {
        pids[i] = fork();
        if(pids[i] == 0)
        {
            if (i == 0)
            {
                execute_close(linked_commnds->in_file_op,linked_commnds->out_file_op,(process - 1) * 2,pipes);
            }
            else if (i + 1  == process)
            {
                execute_close(linked_commnds->in_file_op,linked_commnds->out_file_op,(process - 1) * 2,pipes);
            }
            else
            {
                 execute_close(linked_commnds->in_file_op,linked_commnds->out_file_op,(process - 1) * 2,pipes);
            }
                if(execve(get_path(linked_commnds->cmd_w_arg[0],envp),linked_commnds->cmd_w_arg,NULL) == -1)
                {
                    perror("execve child");
                    exit(1);
                }
                exit(0);
        }
        i++;
        linked_commnds = linked_commnds->next;
    }
    int j = 0;
    while(j < (process - 1) * 2)
    {
        close(pipes[j]);
        j++;
    }
    while(wait(NULL) != -1);
    while(1);
}