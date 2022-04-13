/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:09:05 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/12 21:38:53 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <fcntl.h>

//BUFFER_SIZE
# define BUFFER_SIZE  1000
//END

//EXEC
# include "exec_test.h"
//EXEC

char	**split_input(char *input);
char	**alloc_words(int *arr, int words, char **ret);
char	**fill_me(char **split_input, char *string);
char	*t_strjoin(char *s1, char *s2);
char	*get_without_nl(char *string);
int		another_quote(char *string, int *i1, char *split_string, int *i);
int		count_words(char *string);
int		find_quote(char *string, int i);
int		*len_words(int size, char *string);
int		*ft_calloc(int size);
int		find_end(char *string, int *i, char *q);
int		f_end(char *string, int *i, int *arr, int *arr_i);
int		in(char *string, int *i1, char *split_input, int *i);
int		another_q(char *string, int *i1, char *split_input, int *i);
void	skip_spaces(char *string, int *i);
void	skip_redirections(char *string, int *i, int *word_count);
void	take_input(char **input);

//Error functions
int		pipe_in_end(char *input);
int		check_errors(char *input);
int		pipe_beggining(char *input);
int		check_after_pipe(char *input, int *i);
int		check_out_red(char *input, int *i);
int		check_in_red(char *input, int *i);
int		check_d_quotes(char *input, int *i);
int		check_s_quotes(char *input, int *i);
int		check_do(char *input, int *i);
//Error functions end

//Dollar handling
void	check_dollar(char *input, int *i1, char **split_input, t_env *env);
void	check_env(char *input, char **split_input, t_env *env);
void	skip_red2(char *input, int *i1, int *i2);
void	get_dollar1(char *input, int *i1, char **string, t_env *env);
void	get_dol_double_q(char *input, int *i1, char **string, t_env *env);
void	get_single_q_dollar(char *input, int *i1, char **string);
void	get_after_q2(char *input, int *i1, char **string, t_env *env);
void	skip_for_exp(char *input, int *i1, int *i2t);
char	*char_join(char *string, char c);
int		le(char *string);
//Dollar handling

void	skip_words(char *string, int *i, int *word_count);
void	skip_quotes(char *string, int *i, int *word_count);
void	pipe_size(int *arr, int *arr_i);
void	redirection_size(char *string, int *i, int *arr, int *arr_i);
void	word_size(char *string, int *i, int *arr, int *arr_i);
void	quotes_size(char *string, int *i, int *arr, int *arr_i);
void	go_to_quote(char *string, int *i, char q);
void	g_quote(char *string, int *i, int *n, char q);
void	add_pipe(char *split_input, int *i2);
void	add_redi(char *string, int *i1, char *split_input, int *i2);
void	add_word(char *string, int *i1, char *split_input, int *i2);
void	add_in_quote(char *string, int *i1, char *split_input, int *i2);
void	to_quote(char *string, int *i1, char *split_input, int *i);
void	go_to_quote2(char *string, int *i1, char *split_input, int *i);
void	add_zero(char *string, int *i1, char *split_input, int *i);
void	inc_dec(int *i1, int *i2);

//Ft_split
int		coun(char *st, char deli);
int		*len_of_w(char *my_string, char dtr);
int		give_index(char *sttt, char ddd);
char	**copy_strings(char **re_string, char *strii, char dm, int n);
char	**ft_split_parsing(char *s, char d);

//Search in env test
char	*search_in_env1(t_env *env, char *var);
int		f_isalpha(char c);
int		f_isdigit(char c);
int		check_dollar_end(char **str, int *i, char *string);
void	env_join(char **string, char *string1, t_env *en, int *i);
void	join_mark(char **ret_string, char *split_string, int *i);

//get_next_line
//char	*without_nl(char *s);
char	*get_next_line(int fd);
char	*ft_strdup_parsing(char *string);
char	*ft_strdup_execution(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*read_file(int fd);
char	*get_before_nl(char *buffer, int option);
char	*join_and_free(char *ret_string, char *buffer);
void	get_after_nl(char *buff);
void	ft_zero(char *buff);
int		check_nl(char *string);
int		f_strlen(char *string);

//Parsing final step
void	create_list(t_cmd **structure);
void	alloc_words2(char **ret, char **split, int len);
char	**remove_null(char **split, int nb);
t_cmd	*parse_everything(char **split_input, int nb);
t_cmd	*alloc_linked_list(char **split);

//Opening files
void	open_files(char **split_input2, int *i, t_cmd *tmp);
void	append_red(t_cmd *cmd, char *file);
void	in_output_red(t_cmd *cmd, char *file, char option);
void	in2(t_cmd *cmd, char *file);

//Pushing arguments
void	push_string(char *to_push, t_cmd *cmd);
void	here_doc_p(char **split_input, int *i, t_cmd *cmd);
void	here_doc_p(char **split_input, int *i, t_cmd *cmd);
void	push_limiter(char *to_push, t_cmd *cmd);
int		len_dp(char **p);

//Leaks
void	free_all(char **p, char *p2, int n, t_cmd *com);
void	free_split_in(char **s);
void	free_double_p(char **s);
void	free_com_list(t_cmd *com);

//History
void	history_check(void);
void	add_h(char *input);

#endif
