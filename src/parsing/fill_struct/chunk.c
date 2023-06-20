/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:59:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/20 17:10:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_chunk	*create_chunk(void)
{
	t_chunk	*new;

	new = (t_chunk *)g_shx->gc->malloc(sizeof(t_chunk), true);
	if (!new)
		return (NULL);
	new->txt = NULL;
	new->txt = (char **)g_shx->gc->malloc(sizeof(char *) * 5, true);
	if (!new->txt)
		return (NULL);
	new->end = 0;
	new->type = 0;
	new->start = 0;
	new->blocks = NULL;
	new->under_chunk = NULL;
	return (new);
}

t_chunk	*new_chunk(t_uint c_start, t_uint c_end, t_str *splited, t_uint type)
{
	t_chunk	*chunk;

	if ((c_start < 0 || c_end < 0) || (c_start == c_end) || !splited)
		return (printf("New_chuck check var error\n"), NULL);
	chunk = create_chunk();
	if (!chunk)
		return (printf("chunk  malloc error\n"), NULL);
	chunk->end = c_end;
	chunk->start = c_start;
	chunk->type = type;
	if (type == O_PARENTHESIS || type == C_PARENTHESIS)
		chunk->type = PARENTHESIS;
	t_uint i = 0;
	while (c_start != c_end + 1)
	{
		chunk->txt[i] = ft_strdup(splited[c_start]);
		printf("new_chunk chunk->txt = %s\n", chunk->txt[i]);
		i++;
		c_start++;
	}
	return (chunk);
}
