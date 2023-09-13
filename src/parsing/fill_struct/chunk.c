/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:59:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/13 11:57:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_chunk(
	t_sh_context *shx, t_chunk	**new, t_uint	chunk_lim[2], t_uint type)
{
	*new = (t_chunk *)shx->gc->malloc(shx, sizeof(t_chunk), true);
	if (!(*new))
		return (MALLOC_FAIL);
	(*new)->txt = (char **)shx->gc->malloc(shx,
			sizeof(char *) * ((chunk_lim[1] - chunk_lim[0]) + 1), true);
	if (!(*new)->txt)
		return (MALLOC_FAIL);
	(*new)->start = chunk_lim[0];
	(*new)->end = chunk_lim[1];
	(*new)->type = type;
	(*new)->blocks = NULL;
	(*new)->under_chunk = NULL;
	(*new)->next = NULL;
	(*new)->shx = shx;
	return (0);
}

t_uint	fill_chunk(t_chunk	**chunk, t_uint	chunk_lim[2], t_str *splited)
{
	t_uint	i;

	i = 0;
	while (chunk_lim[0] != chunk_lim[1])
	{
		(*chunk)->txt[i] = ft_strdup((*chunk)->shx, splited[chunk_lim[0]++]);
		if (!(*chunk)->txt[i++])
			return (MALLOC_FAIL);
	}
	(*chunk)->txt[i] = NULL;
	return (0);
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
	t_sh_context *shx, t_chunk **chunk,
	t_uint chunk_lim[2], t_str *splited, t_uint type)
{
	t_uint	status;
	t_chunk	*new;
	t_chunk	*tmp;

	status = create_chunk(shx, &new, chunk_lim, type);
	if (status != 0)
		return (status);
	status = fill_chunk(&new, chunk_lim, splited);
	if (status != 0)
		return (status);
	if (!(*chunk))
		(*chunk) = new;
	else
	{
		tmp = (*chunk);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	status = under_chunk(shx, &new, new->txt);
	if (status != 0)
		return (status);
	return (0);
}
