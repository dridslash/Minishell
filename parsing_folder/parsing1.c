/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:46:07 by oessayeg          #+#    #+#             */
/*   Updated: 2022/04/04 20:14:27 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_list(t_cmd	**structure)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = malloc(sizeof(t_cmd));
	new->next = NULL;
	new->in_file_op = 0;
	new->out_file_op = 1;
	new->here_doc_char = NULL;
	new->how_many_here_doc = 0;
	new->cmd_w_arg = NULL;
	new->limiters = NULL;
	if (*structure == NULL)
	{
		*structure = new;
		return ;
	}
	tmp = *structure;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

char	**remove_null(char **split, int nb)
{
	char	**ret;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (++i < nb)
	{
		if (split[i] != NULL)
			len++;
	}
	ret = malloc(sizeof(char *) * (len + 1));
	alloc_words2(ret, split, nb);
	return (ret);
}

void	alloc_words2(char **ret, char **split, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		if (split[i] != NULL)
		{
			ret[j] = ft_strdup_parsing(split[i]);
			j++;
		}
		i++;
	}
	ret[j] = NULL;
}

t_cmd	*parse_everything(char **split_input, int nb)
{
	t_cmd	*tmp;
	t_cmd	*ret_struct;
	char	**split_input2;
	int		i;

	i = -1;
	split_input2 = remove_null(split_input, nb);
	ret_struct = alloc_linked_list(split_input2);
	tmp = ret_struct;
	while (split_input2[++i])
	{
		if (split_input2[i][0] == '\v')
			tmp = tmp->next;
		else if (ft_strcmp(split_input2[i], ">") == 0
			|| ft_strcmp(split_input2[i], "<") == 0
			|| ft_strcmp(split_input2[i], ">>") == 0
			|| ft_strcmp(split_input2[i], "<>") == 0)
			open_files(split_input2, &i, tmp);
		else if (ft_strcmp(split_input2[i], "<<") == 0)
			here_doc_p(split_input2, &i, tmp);
		else
			push_string(split_input2[i], tmp);
	}
	free_double_p(split_input2);
	return (ret_struct);
}

t_cmd	*alloc_linked_list(char **split)
{
	int		n_pipe;
	int		i;
	t_cmd	*ret;

	i = -1;
	n_pipe = 0;
	ret = NULL;
	while (split[++i])
		if (ft_strcmp(split[i], "\v") == 0)
			n_pipe++;
	i = -1;
	while (++i <= n_pipe)
		create_list(&ret);
	return (ret);
}
