/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:17:48 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/20 17:26:07 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_chunk	*chunk_size(t_str *splited)
{
	t_uint	i;
	t_uint	n;
	t_uint	c_start;
	t_uint	c_end;
	t_uint	meta;

	i = 0;
	n = 0;
	while (splited[i])
	{
		meta = get_meta_char(&splited[i][0]);
		if ((meta >= SINGLE_QUOTE && meta <= O_PARENTHESIS) && n == 0)
		{
			c_start = i;
			n = 1;
		}
		else if ((meta >= SINGLE_QUOTE && meta <= C_PARENTHESIS)
			&& n == 1)
			c_end = i;
		i++;
	}
	if (meta >= SINGLE_QUOTE && meta <= C_PARENTHESIS)
		return (new_chunk(c_start + 1, c_end - 1, splited, meta));
	return (printf("chunk_size = NULL\n"), NULL);
}
