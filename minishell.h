/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:13:11 by oessayeg          #+#    #+#             */
/*   Updated: 2022/03/18 14:56:12 by oessayeg         ###   ########.fr       */
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
char	**push(char *input, int i, char **pt, int *stop);
char	**alloc_space(char *input, int i, int stop, char *pt);
int		len_of(char **string);

#endif
