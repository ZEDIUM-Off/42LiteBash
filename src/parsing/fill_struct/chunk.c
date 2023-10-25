/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:59:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/10/24 15:14:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_chunk(
	t_sh_context *shx, t_chunk	**new, t_uint	chunk_lim[2], t_uint type)
{
	*new = (t_chunk *)shx->gc->malloc(shx, sizeof(t_chunk), true);
	if (!(*new))
		return (handle_error(MALLOC_FAIL, NULL));
	(*new)->txt = (char **)shx->gc->malloc(shx,
			sizeof(char *) * ((chunk_lim[1] - chunk_lim[0]) + 1), true);
	if (!(*new)->txt)
		return (handle_error(MALLOC_FAIL, NULL));
	(*new)->start = chunk_lim[0];
	(*new)->end = chunk_lim[1];
	(*new)->type = type;
	(*new)->next = NULL;
	(*new)->shx = shx;
	return (CONTINUE_PROC);
}

t_uint	fill_chunk(t_chunk	**chunk, t_uint	chunk_lim[2], t_str *splited)
{
	t_uint	i;

	i = 0;
	while (chunk_lim[0] != chunk_lim[1])
	{
		(*chunk)->txt[i] = ft_strdup((*chunk)->shx, splited[chunk_lim[0]++]);
		if (!(*chunk)->txt[i++])
			return (handle_error(MALLOC_FAIL, NULL));
	}
	(*chunk)->txt[i] = NULL;
	return (CONTINUE_PROC);
}

t_uint	last_chunk_end(t_chunk **chunk)
{
	t_chunk	*tmp;

	tmp = (*chunk);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->end);
}

t_uint	new_chunk(
	t_sh_context *shx, t_chunk_utils *chunk_utils, t_uint type)
{
	t_uint	status;
	t_chunk	*new;
	t_chunk	*tmp;

	status = create_chunk(shx, &new, chunk_utils->chunk_lim, type);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = fill_chunk(&new, chunk_utils->chunk_lim, chunk_utils->splited);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (!(*(chunk_utils->chunk)))
		(*(chunk_utils->chunk)) = new;
	else
	{
		tmp = (*(chunk_utils->chunk));
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (CONTINUE_PROC);
}
