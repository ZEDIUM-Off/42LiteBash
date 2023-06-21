/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:55:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/21 11:43:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint create_ppl(t_pipeline **new, t_uint size, t_str *splited)
{
	t_uint	status;

	*new = (t_pipeline *)g_shx->gc->malloc(sizeof(t_pipeline), true);
	if (!(*new))
		return (MALLOC_FAIL);
	(*new)->cmd = NULL;
	(*new)->redir = (t_redirect){.in_type = NONE, .out_type = NONE};
	(*new)->next = NULL;
	status = parse_pipe(new, splited, size);
	if (status != 0)
		return (status);
	return (0);
}

t_uint	add_ppl(t_pipeline **pipeline, t_uint size, t_str *splited)
{
	t_pipeline	*new;
	t_pipeline	*tmp;
	t_uint	status;

	status = create_ppl(&new, size, splited);
	if (status != 0)
		return (status);
	if (!*pipeline)
		*pipeline = new;
	else
	{
		tmp = *pipeline;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}
