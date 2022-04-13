/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectuion_her_doc_utils00.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:32:15 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/12 22:13:48 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	do_her_doc_helper_one(t_cmd *holder_nodes)
{
	char	*tmp;

	holder_nodes->here_doc_char = readline(">");
	while ((holder_nodes->here_doc_char != NULL
			&& ft_strcmp(holder_nodes->here_doc_char,
				holder_nodes->limiters[0]) != 0))
	{
		tmp = holder_nodes->here_doc_char;
		holder_nodes->here_doc_char \
				= ft_strjoin_non_free(holder_nodes->here_doc_char, "\n");
		free(tmp);
		write(holder_nodes->fd_her_doc[1],
			holder_nodes->here_doc_char,
			ft_strlen(holder_nodes->here_doc_char));
		free(holder_nodes->here_doc_char);
		holder_nodes->here_doc_char = readline(">");
	}
}

void	do_her_doc_helper_two(t_cmd *holder_nodes, int iterate_her_docs)
{
	char	*tmp;

	holder_nodes->here_doc_char = readline(">");
	while ((holder_nodes->here_doc_char != NULL
			&& ft_strcmp(holder_nodes->here_doc_char,
				holder_nodes->limiters[iterate_her_docs - 1])))
	{
		tmp = holder_nodes->here_doc_char;
		holder_nodes->here_doc_char \
					= ft_strjoin_non_free(holder_nodes->here_doc_char,
			"\n");
		free(tmp);
		free(holder_nodes->here_doc_char);
		holder_nodes->here_doc_char = readline(">");
	}
	if (holder_nodes->here_doc_char)
		free(holder_nodes->here_doc_char);
}

void	do_her_doc_helper_three(t_cmd *holder_nodes,
		int iterate_her_docs)
{
	char	*tmp;

	holder_nodes->here_doc_char = readline(">");
	while ((holder_nodes->here_doc_char != NULL
			&& ft_strcmp(holder_nodes->here_doc_char,
				holder_nodes->limiters[iterate_her_docs - 1])))
	{
		tmp = holder_nodes->here_doc_char;
		holder_nodes->here_doc_char \
				= ft_strjoin_non_free(holder_nodes->here_doc_char,
			"\n");
		free(tmp);
		write(holder_nodes->fd_her_doc[1],
			holder_nodes->here_doc_char,
			ft_strlen(holder_nodes->here_doc_char));
		free(holder_nodes->here_doc_char);
		holder_nodes->here_doc_char = readline(">");
	}
}

void	her_doc_helper_main(t_cmd *holder_nodes)
{
	int	iterate_her_docs;

	iterate_her_docs = 1;
	if (holder_nodes->how_many_here_doc > 0)
	{
		pipe(holder_nodes->fd_her_doc);
		if (holder_nodes->how_many_here_doc == 1)
			do_her_doc_helper_one(holder_nodes);
		else
		{
			while (iterate_her_docs <= holder_nodes->how_many_here_doc)
			{
				if (iterate_her_docs != holder_nodes->how_many_here_doc)
					do_her_doc_helper_two(holder_nodes, iterate_her_docs);
				else
					do_her_doc_helper_three(holder_nodes, iterate_her_docs);
				iterate_her_docs++;
			}
		}
		close(holder_nodes->fd_her_doc[1]);
	}
}
