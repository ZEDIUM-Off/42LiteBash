/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:55:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 13:16:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_ppl(
		t_sh_context *shx, t_pipeline **new, t_uint size, t_str *splited)
{
	t_uint	status;

	*new = (t_pipeline *)shx->gc->malloc(shx, sizeof(t_pipeline), true);
	if (!(*new))
		return (MALLOC_FAIL);
	(*new)->cmd = NULL;
	(*new)->shx = shx;
	(*new)->process = (t_process){.pid = -42, .status = -42};
	(*new)->redir = (t_redirect){.in_type = NONE, .out_type = NONE};
	(*new)->next = NULL;
	status = parse_pipe(shx, new, splited, size);
	printf("create_ppl : size = %d, splited = %s, status = %d\n", size, splited[0], status);
	if (status != 0)
		return (status);
	return (0);
}

t_uint	add_ppl(
		t_sh_context *shx, t_pipeline **pipeline, t_uint size, t_str *splited)
{
	t_pipeline	*new;
	t_pipeline	*tmp;
	t_uint		status;

	printf("new pipeline : size = %d, splited = %s\n", size, splited[0]);
	status = create_ppl(shx, &new, size, splited);
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
