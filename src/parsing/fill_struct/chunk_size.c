/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:17:48 by bfaure            #+#    #+#             */
/*   Updated: 2023/10/25 15:42:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	find_chunk(t_uint *i, bool *chunk_found, t_chunk_utils *chunk_utils)
{
	t_uint	meta;

	while (chunk_utils->splited[*i] && !(*chunk_found))
	{
		meta = get_meta_char(&chunk_utils->splited[*i][0]);
		if (meta >= SINGLE_QUOTE && meta <= DOUBLE_QUOTE)
		{
			*chunk_found = true;
			*i += 1;
			chunk_utils->chunk_lim[0] = *i;
			while (chunk_utils->splited[*i]
				&& meta != get_meta_char(&(chunk_utils->splited[*i][0])))
				*i += 1;
			chunk_utils->chunk_lim[1] = *i;
		}
		*i += 1;
	}
	return (meta);
}

t_uint	chunk_size(
	t_sh_context *shx,
	t_chunk_utils *chunk_utils, t_uint *i, bool *chunk_found)
{
	t_uint	meta;
	t_uint	status;

	*chunk_found = false;
	chunk_utils->chunk_lim[0] = 0;
	chunk_utils->chunk_lim[1] = 0;
	meta = find_chunk(i, chunk_found, chunk_utils);
	if (*chunk_found)
	{
		status = new_chunk(shx, chunk_utils, meta);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	get_chunks(t_sh_context *shx, t_chunk **chunk, t_str *splited)
{
	t_chunk_utils	chunk_utils;
	t_uint			i;
	t_uint			status;
	bool			chunk_found;

	i = 0;
	chunk_found = true;
	chunk_utils.splited = splited;
	chunk_utils.chunk = chunk;
	while (splited[i] && chunk_found)
	{
		status = chunk_size(shx, &chunk_utils, &i, &chunk_found);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (*chunk)
			i = last_chunk_end(chunk) + 1;
	}
	return (CONTINUE_PROC);
}
