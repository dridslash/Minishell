/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:13:11 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/20 17:48:22 by oessayeg         ###   ########.fr       */
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

char	**split_input(char *input);
char	**alloc_words(int *arr, int words, char **ret);
int		count_words(char *string);
int		find_quote(char *string, int i);
int		*len_words(int size, char *string);
int		*ft_calloc(int size);
int		find_end(char *string, int *i, char *q);
void	skip_spaces(char *string, int *i);
void	skip_redirections(char *string, int *i, int *word_count);
void	check_errors(char *input);
void	check_after_pipe(char *input, int *i);
void	check_after_output_redirection(char *input, int *i);
void	check_after_input_redirection(char *input, int *i);
void	check_double_quotes(char *input, int *i);
void	check_single_quotes(char *input, int *i);
void	exit_error(void);
void	skip_words(char *string, int *i, int *word_count);
void	skip_quotes(char *string, int *i, int *word_count);

void	pipe_size(int *arr, int *arr_i);
void	redirection_size(char *string, int *i, int *arr, int *arr_i);
void	word_size(char *string, int *i, int *arr, int *arr_i);
void	quotes_size(char *string, int *i, int *arr, int *arr_i);
void	go_to_quote(char *string, int *i, char q);
void	g_quote(char *string, int *i, int *arr, int *arr_i);
#endif
