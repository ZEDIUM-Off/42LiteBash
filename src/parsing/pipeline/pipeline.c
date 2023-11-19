/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:55:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/15 17:06:24 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_ppl(
		t_sh_context *shx, t_pipeline **new, t_uint size, t_str *splited)
{
	t_uint	status;

	*new = (t_pipeline *)shx->gc->malloc(shx, sizeof(t_pipeline), true);
	if (!(*new))
		return (handle_error(MALLOC_FAIL, NULL));
	(*new)->cmd = NULL;
	(*new)->shx = shx;
	(*new)->size = size;
	(*new)->process = (t_process){.pid = -42, .status = -42};
	(*new)->redir = (t_redirect){.in_type = NONE, .out_type = NONE};
	(*new)->next = NULL;
	status = parse_pipe(shx, new, splited);
	printf("create_ppl status: %d\n", status);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}

t_uint	add_ppl(
		t_sh_context *shx, t_pipeline **pipeline, t_uint size, t_str *splited)
{
	t_pipeline	*new;
	t_pipeline	*tmp;
	t_uint		status;

	status = create_ppl(shx, &new, size, splited);
	printf("add_ppl status: %d\n", status);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (!*pipeline)
		*pipeline = new;
	else
	{
		tmp = *pipeline;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (CONTINUE_PROC);
}
