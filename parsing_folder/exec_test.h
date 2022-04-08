/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:55:19 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/08 17:25:50 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_TEST_H
# define EXEC_TEST_H

//MAX_CHARACTERS_FOR_PATH_NAME
# define FILE_N_MAX 256

// GLOBAL VARIABLE FOR STATUS
int exit_status;

//EXECUTION

//HEADERS_NEEDED_FOR_EXECUTION

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
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
void	handle_q_mark(t_cmd *cmd);
int		find_tab(char *cmd_of_arg);
t_env	*bring_last(t_env *father_of_env);
void	create_env(t_env **envv, char *path_env);
char	*search_in_env(t_env **envv, char *your_var);
int		ft_strcmp(char *s1, char *s2);
char	*get_name_of_env_var(char *tb);
char	*get_after_equal(char *your_path);
int		ft_strlen(char *string);
char	*get_after_dollar(char *your_path);
void	sort_alpha(t_env **envv, int out_file);
int		get_equal_index(char *table);
char	*get_after_equal(char *your_path);
char	*get_after_dollar(char *your_path);
int		get_index_of_env_var(t_env **envv, char *your_path);
void	append_env_vr(t_env **envv, char *var);
int		check_for_minus(char *your_path);
int		check_for_plus(char *your_path);
int		check_for_plus_to_export(char *your_path);
int		check_for_digits(char *your_path);
int		check_for_space(char *your_path);
int		check_simple_quote(char *your_path);
int		check_empty_path_name(char *your_path);
int		check_if_there_is_a_dollar(char *your_path);
int		check_is_exportable(char *your_path);
int		check_errors_export(char *your_path);
int		part_one_of_export(t_cmd *cmd, t_env **env_var);
int		part_two_of_export(t_cmd *cmd, t_env **env_var);
int		handle_dollar_export(t_cmd *cmd, t_env **env_var);
int		charachter_eater(t_cmd *cmd, int is_there_stopper_newline, int start);
int		minus_ns(t_cmd *cmd, int start);
int		how_many_args(t_cmd *cmd, int start);
void	sub_echo_helper(t_cmd *cmd, int args, int option_of_echo, int out_file);
void	sub_echo_helper_two(t_cmd *cmd,
			int args, int option_of_echo, int out_file);
int		search_for_status(char *cmd_of_arg);
void	echo_status(char **cmd_of_arg, int args);
int		ft_error(t_cmd *cmd,t_env *env_var);
int		is_there_a_built_in(t_cmd *holder_nodes);
char	*which_built_in(t_cmd *holder_nodes);
char	**fill_envp(t_env *env_var);

//BUILT_INS

void	ft_pwd(t_cmd *cmd, t_env *env_var, int out_file);
void	ft_cd(t_cmd *cmd, t_env *env_var);
void	ft_export_var(t_cmd *cmd, t_env **env_var, int out_file);
void	env_show(t_cmd *cmd, t_env **env_var, int out_file);
void	ft_echo(t_cmd *cmd, int out_file);
void	ft_unset(t_env **env_var, t_cmd *cmd);
void	ft_exit(t_cmd *cmd);

//END_OF_BUILT_INS

//EXECUTION
//FUNTIONS_NEEDED_FOR_EXECUTION

char	*search_test(t_env **envv, char *your_var);
char	**ft_split_execution(char const *s, char c);
int	execution_help_of_hlp(t_cmd *holder_nodes,
			int iterate_for_fds, int iterate, int *pipes, t_env **env_var);
void	execution_help_of_hlp_two(t_cmd *holder_nodes,
			int iterate_for_fds, int iterate, int *pipes,  t_env **env_var);
void	execution_hlp_main_one(t_cmd *holder_nodes,
			int iterate_for_fds, int iterate, int *pipes,  t_env **env_var);
void	execution_hlp_main_two(t_cmd *holder_nodes,
			int iterate_for_fds, int iterate, int *pipes,  t_env **env_var);
void	exectuion_hlp_main_three(t_cmd *holder_nodes,
			int iterate_for_fds, int iterate, int *pipes,  t_env **env_var);
char	*ft_substr(char	*s, unsigned int start, int len);
int		ft_strchr(char *s, int c);
char	*get_next_line_execution(int fd);
char	*ft_strtrim(char	*s1, char	*set);
int		count_size_of_list(t_cmd *cmd);
int		is_there_a_her_doc(t_cmd	*cmd);
int		execute_commands(t_cmd *cmd,
			t_env **env_var, int *pipes, int original_cmds);
void	execute_cmds_close_files(int in_file,
			int out_file, int fds, int *pipes);
int		execute_command(t_cmd *cmd, t_env **env_var, int original_cmds);
void	her_doc_helper_main(t_cmd *holder_nodes,
			t_env *env_var, int original_cmds);
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
char	*ft_itoa(int n);

//END_OF_FUNCTIONS_NEEDED_FOR_EXECUTION

#endif
