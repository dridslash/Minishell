/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:13:11 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/19 16:07:15 by oessayeg         ###   ########.fr       */
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

char	**split_first_input(char *input);
char	**split_input(char *input);
int		count_words(char *string);
int		find_quote(char *string, int i);
void	skip_spaces(char *string, int *i);
void	skip_redirections(char *string, int *i, int *word_count);
void	check_errors(char *input);
void	check_after_pipe(char *input, int *i);
void	check_after_output_redirection(char *input, int *i);
void	check_after_input_redirection(char *input, int *i);
void	exit_error(void);
void	skip_words(char *string, int *i, int *word_count);
void	skip_quotes(char *string, int *i, int *word_count);

#endif
