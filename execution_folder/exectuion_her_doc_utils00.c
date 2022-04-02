/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectuion_her_doc_utils00.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:32:15 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/02 16:32:38 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

void	do_her_doc_helper_one(t_cmd *holder_nodes,
		t_env *env_var, int original_cmds)
{
	holder_nodes->here_doc_char = readline(">");
	while (holder_nodes->here_doc_char == NULL
		|| ft_strcmp(holder_nodes->here_doc_char,
			holder_nodes->limiters[0]))
	{
		if (holder_nodes->here_doc_char != NULL)
		{
			holder_nodes->here_doc_char \
				= ft_strjoin_non_free(holder_nodes->here_doc_char, "\n");
			write(holder_nodes->fd_her_doc[1],
				holder_nodes->here_doc_char,
				ft_strlen(holder_nodes->here_doc_char));
		}
		free(holder_nodes->here_doc_char);
		holder_nodes->here_doc_char = readline(">");
	}
}

void	do_her_doc_helper_two(t_cmd *holder_nodes,
	t_env *env_var, int original_cmds, int iterate_her_docs)
{
	holder_nodes->here_doc_char = readline(">");
	while (holder_nodes->here_doc_char == NULL
		|| ft_strcmp(holder_nodes->here_doc_char,
			holder_nodes->limiters[iterate_her_docs - 1]))
	{
		if (holder_nodes->here_doc_char != NULL)
		{
			holder_nodes->here_doc_char \
				= ft_strjoin_non_free(holder_nodes->here_doc_char,
				"\n");
		}
		free(holder_nodes->here_doc_char);
		holder_nodes->here_doc_char = readline(">");
	}
}

void	do_her_doc_helper_three(t_cmd *holder_nodes,
	t_env *env_var, int original_cmds, int iterate_her_docs)
{
	holder_nodes->here_doc_char = readline(">");
	while (holder_nodes->here_doc_char == NULL
		|| ft_strcmp(holder_nodes->here_doc_char,
			holder_nodes->limiters[iterate_her_docs - 1]))
	{
		if (holder_nodes->here_doc_char != NULL)
		{
			holder_nodes->here_doc_char \
					= ft_strjoin_non_free(holder_nodes->here_doc_char,
				"\n");
			write(holder_nodes->fd_her_doc[1],
				holder_nodes->here_doc_char,
				ft_strlen(holder_nodes->here_doc_char));
		}
		free(holder_nodes->here_doc_char);
		holder_nodes->here_doc_char = readline(">");
	}
}

void	her_doc_helper_main(t_cmd *holder_nodes,
	t_env *env_var, int original_cmds)
{
	int	iterate_her_docs;

	iterate_her_docs = 1;
	if (holder_nodes->how_many_here_doc > 0)
	{
		pipe(holder_nodes->fd_her_doc);
		if (holder_nodes->how_many_here_doc == 1)
			do_her_doc_helper_one(holder_nodes, env_var, original_cmds);
		else
		{
			while (iterate_her_docs <= holder_nodes->how_many_here_doc)
			{
				if (iterate_her_docs != holder_nodes->how_many_here_doc)
					do_her_doc_helper_two(holder_nodes,
						env_var, original_cmds, iterate_her_docs);
				else
					do_her_doc_helper_three(holder_nodes,
						env_var, original_cmds, iterate_her_docs);
				iterate_her_docs++;
			}
		}
		close(holder_nodes->fd_her_doc[1]);
	}
}