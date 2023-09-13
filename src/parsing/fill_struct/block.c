/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:46:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 13:41:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_block(t_sh_context *shx, t_block **new)
{
	t_uint	size;

	*new = (t_block *)shx->gc->malloc(shx, sizeof(t_block), true);
	if (!(*new))
		return (MALLOC_FAIL);
	(*new)->ppl = NULL;
	(*new)->next = NULL;
	(*new)->shx = shx;
	size = 0;
	while (shx->line_split[size])
		size++;
	(*new)->block_end = size;
	return (0);
}

t_uint	add_block(t_sh_context *shx, t_block **block)
{
	t_block	*new;
	t_uint	status;

	status = create_block(shx, &new);
	if (status != 0)
		return (status);
	if (!*block)
		*block = new;
	else
		printf("block already exists\n");
	printf("add_block : block = %p, new = %p\n", *block, new);
	return (0);
}
