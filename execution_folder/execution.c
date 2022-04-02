/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:03:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/02 11:42:01 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

static void execute_cmds_close_files(int in_file,int out_file,int fds,int *pipes)
{
   int i;

    i = 0;
    dup2(in_file,0);
    dup2(out_file,1);
    while(i < fds)
    {
        close(pipes[i]);
        i++;
    }
}

static void just_close(int *pipes, int original_cmds)
{
    int j;

    j = 0;
    while (j < (original_cmds - 1) * 2)
    {
        close(pipes[j]);
        j++;
    }
}


static void create_pipes(int **pipes, int how_many_cmds)
{
    int iterate;

    iterate = 0;
    int *holder_pipe = malloc(sizeof(int) * (how_many_cmds - 1) * 2);
    while((iterate < (how_many_cmds - 1) * 2))
    {
        pipe(&holder_pipe[iterate]);
        iterate+=2;
    }
    *pipes = holder_pipe;
}

static int count_size_of_list(t_cmd *cmd)
{
    int i;

    i = 0;
    while (cmd != NULL)
    {
        i++;
        cmd = cmd->next;
    }
    return (i);
}

void her_doc_helper(t_cmd *holder_nodes, t_env *env_var, int original_cmds)
{
    int     iterate_her_docs;

    iterate_her_docs = 1;
    if(holder_nodes->how_many_here_doc > 0)
            {
                pipe(holder_nodes->fd_her_doc);
                if(holder_nodes->how_many_here_doc == 1)
                {
                   holder_nodes->here_doc_char = readline(">");
                   while(holder_nodes->here_doc_char == NULL || ft_strcmp(holder_nodes->here_doc_char,holder_nodes->limiters[0]))
                   {
                        if(holder_nodes->here_doc_char != NULL)
                        {
                            holder_nodes->here_doc_char = ft_strjoin_non_free(holder_nodes->here_doc_char,"\n");
                            write(holder_nodes->fd_her_doc[1],holder_nodes->here_doc_char,ft_strlen(holder_nodes->here_doc_char));
                        }
                        free(holder_nodes->here_doc_char);
                        holder_nodes->here_doc_char = readline(">");
                    }
                }
                else
                {
                    while(iterate_her_docs <= holder_nodes->how_many_here_doc)
                    {
                        if (iterate_her_docs != holder_nodes->how_many_here_doc)
                        {
                            holder_nodes->here_doc_char = readline(">");
                            while(holder_nodes->here_doc_char == NULL || ft_strcmp(holder_nodes->here_doc_char,holder_nodes->limiters[iterate_her_docs - 1]))
                            {
                                if(holder_nodes->here_doc_char != NULL)
                                {
                                    holder_nodes->here_doc_char = ft_strjoin_non_free(holder_nodes->here_doc_char,"\n");
                                }
                                free(holder_nodes->here_doc_char);
                                holder_nodes->here_doc_char = readline(">");
                            }
                        }
                        else
                        {
                            holder_nodes->here_doc_char = readline(">");
                            while(holder_nodes->here_doc_char == NULL || ft_strcmp(holder_nodes->here_doc_char,holder_nodes->limiters[iterate_her_docs - 1]))
                            {
                                if(holder_nodes->here_doc_char != NULL)
                                {
                                    holder_nodes->here_doc_char = ft_strjoin_non_free(holder_nodes->here_doc_char,"\n");
                                    write(holder_nodes->fd_her_doc[1],holder_nodes->here_doc_char,ft_strlen(holder_nodes->here_doc_char));
                                }
                                free(holder_nodes->here_doc_char);
                                holder_nodes->here_doc_char = readline(">");
                            }
                        }
                        iterate_her_docs++;
                    }
                }
                close(holder_nodes->fd_her_doc[1]);
            }
}

int execute_her_docs(t_cmd *cmd, t_env *env_var, int original_cmds , int *pipes)
{
    int     iterate;
    int     iterate_for_fds;
    int     iterate_her_docs;
    int     *pids;
    t_cmd   *holder_nodes;
    holder_nodes = cmd;
    pids = malloc(sizeof(int) * original_cmds);
    iterate = 0;
    iterate_for_fds = 0;
    iterate_her_docs = 1;
    while(holder_nodes)
    {
        her_doc_helper(holder_nodes,env_var,original_cmds);
        holder_nodes = holder_nodes->next;
    }
    holder_nodes = cmd;
    while(iterate < original_cmds && (holder_nodes))
    {
        pids[iterate] = fork();
        if(pids[iterate] == 0)
        {
            if(iterate == 0)
            {
                if(iterate + 1 == original_cmds)
                {
                    if(holder_nodes->how_many_here_doc > 0)
                    {
                    execute_cmds_close_files(holder_nodes->fd_her_doc[0],holder_nodes->out_file_op,(original_cmds - 1) * 2,pipes);
                    close(holder_nodes->fd_her_doc[0]);
                    close(holder_nodes->fd_her_doc[1]);
                    }
                else
                {
                    execute_cmds_close_files(holder_nodes->in_file_op,holder_nodes->out_file_op,(original_cmds - 1) * 2,pipes);
                }
                }
                else
                {
                if(holder_nodes->how_many_here_doc > 0)
                {
                    execute_cmds_close_files(holder_nodes->fd_her_doc[0],pipes[iterate_for_fds + 1],(original_cmds - 1) * 2,pipes);
                    close(holder_nodes->fd_her_doc[0]);
                    close(holder_nodes->fd_her_doc[1]);
                }
                else
                {
                    execute_cmds_close_files(holder_nodes->in_file_op,pipes[iterate_for_fds + 1],(original_cmds - 1) * 2,pipes);
                }
                }
            }
            else if (iterate + 1 == original_cmds)
             {
                if(holder_nodes->how_many_here_doc > 0)
                {
                execute_cmds_close_files(holder_nodes->fd_her_doc[0],holder_nodes->out_file_op,(original_cmds - 1) * 2,pipes);
                close(holder_nodes->fd_her_doc[0]);
                close(holder_nodes->fd_her_doc[1]);
                }
                else
                {
                execute_cmds_close_files(pipes[iterate_for_fds - 2],holder_nodes->out_file_op,(original_cmds - 1) * 2,pipes);
                }
            }
            else
            {
                if(holder_nodes->how_many_here_doc > 0)
                {
                execute_cmds_close_files(holder_nodes->fd_her_doc[0],pipes[iterate_for_fds + 1],(original_cmds - 1) * 2,pipes);
                close(holder_nodes->fd_her_doc[0]);
                close(holder_nodes->fd_her_doc[1]);
                }
                else
                {
                execute_cmds_close_files(pipes[iterate_for_fds - 2],pipes[iterate_for_fds + 1],(original_cmds - 1) * 2,pipes);
                }
            }
            execve(get_path(holder_nodes->cmd_w_arg[0],env_var),holder_nodes->cmd_w_arg,NULL);
            return (0);
        }
        iterate++;
        iterate_for_fds+=2;
        holder_nodes = holder_nodes->next;
    }
    return (0);
}

int execute_commands(t_cmd *cmd, t_env *env_var, int *pipes, int original_cmds)
{
    t_cmd   *holder_nodes;
    int     iterate;
    int     iterate_for_fds;
    int     *pids;

    holder_nodes = cmd;
    pids = malloc(sizeof(int) * original_cmds);
    iterate = 0;
    iterate_for_fds = 0;
    while(iterate < original_cmds && (holder_nodes))
    {
        pids[iterate] = fork();
        if(pids[iterate] == 0)
        {
        if (iterate == 0)
        {
            execute_cmds_close_files(holder_nodes->in_file_op,pipes[iterate_for_fds + 1],(original_cmds - 1) * 2,pipes);
        }
        else if (iterate + 1 == original_cmds)
        {
            execute_cmds_close_files(pipes[iterate_for_fds - 2],holder_nodes->out_file_op,(original_cmds - 1) * 2,pipes);
        }
        else
        {
            execute_cmds_close_files(pipes[iterate_for_fds - 2],pipes[iterate_for_fds + 1],(original_cmds - 1) * 2,pipes);
        }
        execve(get_path(holder_nodes->cmd_w_arg[0],env_var),holder_nodes->cmd_w_arg,NULL);
        return (0);
        }
        iterate++;
        iterate_for_fds+=2;
        holder_nodes = holder_nodes->next;
    }
    return (0);
}

int execute_command(t_cmd *cmd, t_env *env_var, int original_cmds)
{
    (void)original_cmds;
    int pid = 0;
    pid = fork();
    if(pid == 0)
    {
        dup2(cmd->in_file_op,0);
        dup2(cmd->out_file_op,1);
        execve(get_path(cmd->cmd_w_arg[0],env_var),cmd->cmd_w_arg,NULL);
        return (0);
    }
    waitpid(pid,NULL,0);
    return (0);
}


static int is_there_a_her_doc(t_cmd  *cmd)
{
    t_cmd *tmp = cmd;
    while(tmp != NULL)
    {
        if(tmp->how_many_here_doc > 0)
        {
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}


void close_pipe_wait(int *pipes,int original_cmds)
{
    int j;

    j = 0;
    while (j < (original_cmds - 1) * 2)
    {
        close(pipes[j]);
        j++;
    }
    while(wait(NULL) != -1);
}

int main_execution_func(t_cmd *cmd,t_env *env_var)
{
    int     *pipes;
    int     original_cmds;
    
    original_cmds = count_size_of_list(cmd);
    create_pipes(&pipes, original_cmds);
    if (original_cmds > 1 && is_there_a_her_doc(cmd) == 0)
    execute_commands(cmd,env_var,pipes,original_cmds);
    if (original_cmds == 1 && is_there_a_her_doc(cmd) == 0)
    execute_command(cmd, env_var,original_cmds);
    if (is_there_a_her_doc(cmd))
    execute_her_docs(cmd,env_var,original_cmds,pipes);
    close_pipe_wait(pipes, original_cmds);
    return (0);
}