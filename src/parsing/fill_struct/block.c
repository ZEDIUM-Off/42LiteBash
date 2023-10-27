/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:46:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/27 12:08:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_block(t_sh_context *shx, t_block **new)
{
	t_uint	size;

	*new = (t_block *)shx->gc->malloc(shx, sizeof(t_block), true);
	if (!(*new))
		return (handle_error(MALLOC_FAIL, NULL));
	(*new)->ppl = NULL;
	(*new)->next = NULL;
	(*new)->shx = shx;
	size = 0;
	while (shx->line_split[size])
		size++;
	(*new)->block_end = size;
	return (CONTINUE_PROC);
}

t_uint	add_block(t_sh_context *shx, t_block **block)
{
	t_block	*new;
	t_uint	status;

	status = create_block(shx, &new);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (!*block)
		*block = new;
	return (CONTINUE_PROC);
}
