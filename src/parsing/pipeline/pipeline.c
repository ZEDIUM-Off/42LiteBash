/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:55:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/19 17:56:05 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

// parse_pipe

t_pipeline	*create_ppl(t_uint pipe_pos)
{
	t_pipeline	*new;

	new = (t_pipeline *)g_shx->gc->malloc(sizeof(t_pipeline), true);
	if (!new)
		return (NULL);
	new->next = NULL;
	parse_pipe(&new, pipe_pos);
	return (new);
}

t_pipeline	*add_ppl(t_pipeline **pipeline, t_uint pipe_pos)
{
	t_pipeline	*new;
	t_pipeline	*tmp;

	//trace("add_ppl", "add pipeline" , PARSE);
	new = create_ppl(pipe_pos);
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
	//log_action();
	return (new);
}
