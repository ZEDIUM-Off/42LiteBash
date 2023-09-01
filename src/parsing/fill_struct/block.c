/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:46:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:55:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_block(t_sh_context *shx, t_block **new, t_uint bool_to_next, t_uint split_index)
{
	*new = (t_block *)shx->gc->malloc(shx, sizeof(t_block), true);
	if (!(*new))
		return (MALLOC_FAIL);
	(*new)->ppl = NULL;
	(*new)->next = NULL;
	(*new)->shx = shx;
	(*new)->bool_to_next = bool_to_next;
	(*new)->block_end = split_index;
	return (0);
}

t_uint	add_block(t_sh_context *shx, t_block **block, t_uint bool_to_next, t_uint split_index)
{
	t_block	*new;
	t_block	*tmp;
	t_uint	status;

	status = create_block(shx, &new, bool_to_next, split_index);
	if (status != 0)
		return (status);
	if (!*block)
		*block = new;
	else
	{
		tmp = *block;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}
