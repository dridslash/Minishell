#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>

//EXEC
# include "exec_test.h"
//EXEC
char	**split_input(char *input);
char	**alloc_words(int *arr, int words, char **ret);
char	**fill_me(char **split_input, char *string);
char	*t_strjoin(char *s1, char *s2);
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
char	*char_join(char *string, char c);
char	*search_in_env1();
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
int	coun(char *st, char deli);
int	*len_of_w(char *my_string, char dtr);
char	**copy_strings(char **re_string, char *strii, char dm, int n);
int	give_index(char *sttt, char ddd);
char	**ft_split(char *s, char d);

//Search in env test
char	*search_in_env1(t_env *env, char *var);
#endif
