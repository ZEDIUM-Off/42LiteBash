/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:17:48 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/23 16:33:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	find_chunk(t_str *splited, t_uint *i, bool *chunk_found, t_uint *chunk_lim)
{
	t_uint	meta;

	while (splited[*i] && !(*chunk_found))
	{
		meta = get_meta_char(&splited[*i][0]);
		if (meta >= SINGLE_QUOTE && meta <= O_PARENTHESIS)
		{
			*chunk_found = true;
			chunk_lim[0] = ++(*i);
			if (meta == O_PARENTHESIS)
				meta = C_PARENTHESIS;
			while (meta != get_meta_char(&splited[*i][0]))
				(*i)++;
			chunk_lim[1] = *i;
		}
		(*i)++;
	}
	return meta;
}

t_uint	chunk_size(t_chunk	**chunk, t_str *splited, t_uint *i, bool *chunk_found)
{
	t_uint	chunk_lim[2];
	t_uint	meta;
	t_uint	status;

	*chunk_found = false;
	chunk_lim[0] = 0;
	chunk_lim[1] = 0;
	meta = find_chunk(splited, i, chunk_found, chunk_lim);
	if (*chunk_found)
	{
		status = new_chunk(chunk, chunk_lim, splited, meta);
		if (status != 0)
			return (status);
	}
	return (0);
}

t_uint	get_chunks(t_chunk **chunk, t_str *splited)
{
	t_uint	i;
	t_uint	status;
	bool	chunk_found;

	i = 0;
	chunk_found = true;
	while (splited[i] && chunk_found)
	{
		printf("splited[%d] = %s\n", i, splited[i]);
		status = chunk_size(chunk, splited, &i, &chunk_found);
		if (status != 0)
			return (status);
		i = last_chunk_end(chunk) + 1;
	}
	// while ((*chunk))
	// {
	// 	printf("chunk : start = %d, end = %d, type = %d\n", (*chunk)->start, (*chunk)->end, (*chunk)->type);
	// 	(*chunk) = (*chunk)->next;
	// }
	return (0);
}
