/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:04:12 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/22 19:00:40 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
#define FILE_N_MAX 256

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct t_command
{
    int in_file_op;
    int out_file_op;
    char **cmd_w_arg;
    struct t_command *next;
}t_cmd;

typedef struct t_envir
{
    char *path_env;
    struct t_envir *next_env;
}t_env;


char	**ft_split(char const *s, char c);
void    sort_alpha(t_env **envv);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*get_path(char *cmd, char **envp);
int		count_argc(char **argv);
char	**get_params(int index, char **argv);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int     ft_strcmp(char  *s1,char    *s2);
char	*ft_strjoin_non_free(char  *s1, char  *s2);
void    add_cmd(t_cmd **father_of_cmds , int in_file_op, int out_file_op, char **cmd_w_arg);
int     ft_isdigit(int arg);
int     ft_isalpha(int chr);
int     ft_isascii(int arg);
int     ft_atoi(const char *nptr);

#endif