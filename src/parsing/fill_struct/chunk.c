/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:59:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/29 14:28:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_chunk(t_chunk	**new, t_uint	chunk_lim[2], t_uint type)
{
	*new = (t_chunk *)g_shx->gc->malloc(sizeof(t_chunk), true);
	if (!(*new))
		return (MALLOC_FAIL);
	(*new)->txt = (char **)g_shx->gc->malloc(sizeof(char *) * ((chunk_lim[1] - chunk_lim[0]) + 1), true);
	if (!(*new)->txt)
		return (MALLOC_FAIL);
	(*new)->start = chunk_lim[0];
	(*new)->end = chunk_lim[1];
	(*new)->type = type;
	(*new)->blocks = NULL;
	(*new)->under_chunk = NULL;
	(*new)->next = NULL;
	return (0);
}

t_uint	fill_chunk(t_chunk	**chunk, t_uint	chunk_lim[2], t_str *splited)
{
	t_uint	i;
	t_uint	status;
	
	i = 0;
	while (chunk_lim[0] != chunk_lim[1])
		(*chunk)->txt[i++] = ft_strdup(splited[chunk_lim[0]++]);
	(*chunk)->txt[i] = NULL;
	if ((*chunk)->type == PARENTHESIS)
	{
		status = pars_line(&(*chunk)->blocks, (*chunk)->txt);
		if (status != 0)
			return (status);
	}
	return (0);
}

t_uint	last_chunk_end(t_chunk **chunk)
{
	t_chunk *tmp;

	tmp = (*chunk);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->end);
}

t_uint	new_chunk(t_chunk	**chunk, t_uint	chunk_lim[2], t_str *splited, t_uint type)
{
	t_uint	status;
	t_chunk	*new;
	t_chunk	*tmp;

	if (type == C_PARENTHESIS)
		type = PARENTHESIS;
	status = create_chunk(&new, chunk_lim, type);
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
	status = under_chunk(&new, new->txt);
	if (status != 0)
		return (status);
	return (0);
}
