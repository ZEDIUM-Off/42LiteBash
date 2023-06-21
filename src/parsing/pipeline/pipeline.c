/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:55:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/20 15:00:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

// parse_pipe

t_pipeline	*create_ppl(t_uint size, t_str *splited)
{
	t_pipeline	*new;

	new = (t_pipeline *)g_shx->gc->malloc(sizeof(t_pipeline), true);
	if (!new)
		return (NULL);
	new->cmd = NULL;
	new->redir = (t_redirect){.in_type = NONE, .out_type = NONE};
	new->next = NULL;
	if (!parse_pipe(&new, splited, size))
		return (NULL);
	return (new);
}

t_pipeline	*add_ppl(t_pipeline **pipeline, t_uint size, t_str *splited)
{
	t_pipeline	*new;
	t_pipeline	*tmp;

	new = create_ppl(size, splited);
	if (!new)
		return (NULL);
	if (!*pipeline)
		*pipeline = new;
	else
	{
		tmp = *pipeline;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}
