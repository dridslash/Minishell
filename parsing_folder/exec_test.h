/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:55:19 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/02 18:22:00 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_TEST_H
# define EXEC_TEST_H

//MAX_CHARACTERS_FOR_PATH_NAME
# define FILE_N_MAX 256

//EXECUTION

//HEADERS_NEEDED_FOR_EXECUTION

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

//END_OF_HEADERS

typedef struct t_envir
{
	char			*path_env;
	struct t_envir	*next_env;
}t_env;

typedef struct t_command
{
	char				*here_doc_char;
	char				**limiters;
	int					how_many_here_doc;
	int					in_file_op;
	int					out_file_op;
	char				**cmd_w_arg;
	int					fd_her_doc[2];
	int					size_of_list;
	int					iterate;
	struct t_command	*next;
}t_cmd;

t_env	*ft_env(char **envi);
t_env	*bring_last(t_env *father_of_env);
void	create_env(t_env **envv, char *path_env);
char	*search_in_env(t_env **envv, char *your_var);
int		ft_strcmp(char *s1, char *s2);
char	*get_name_of_env_var(char *tb);
char	*get_after_equal(char *your_path);
int		ft_strlen(char *string);
char	*get_after_dollar(char *your_path);
//EXECUTION
//FUNTIONS_NEEDED_FOR_EXECUTION

char	*search_test(t_env **envv, char *your_var);
char	**ft_split_execution(char const *s, char c);
void	sort_alpha(t_env **envv);
char	*ft_substr(char	*s, unsigned int start, int len);
int		ft_strchr(char *s, int c);
char	*get_next_line_execution(int fd);
char	*ft_strtrim(char	*s1, char	*set);
int		count_size_of_list(t_cmd *cmd);
int		is_there_a_her_doc(t_cmd	*cmd);
int		execute_commands(t_cmd *cmd,
			t_env *env_var, int *pipes, int original_cmds);
void	execute_cmds_close_files(int in_file,
			int out_file, int fds, int *pipes);
int		execute_command(t_cmd *cmd, t_env *env_var, int original_cmds);
void	her_doc_helper_main(t_cmd *holder_nodes, t_env *env_var, int original_cmds);
int		execute_her_docs(t_cmd *cmd, t_env *env_var,
			int original_cmds, int *pipes);
// char    *ft_strjoin(char const *s1, char const *s2);
// char    *ft_strdup(const char *src);
int		main_execution_func(t_cmd	*cmd, t_env	*env_var);
char	*get_path(char *cmd, t_env *envp);
int		count_argc(char **argv);
char	**get_params(int index, char **argv);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strcmp(char	*s1, char	*s2);
char	*ft_strjoin_non_free(char	*s1, char	*s2);
int		ft_isdigit(int arg);
int		ft_isalpha(int chr);
int		ft_isascii(int arg);
int		ft_atoi(const char *nptr);

//END_OF_FUNCTIONS_NEEDED_FOR_EXECUTION

#endif
