/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:46:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/14 10:05:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_block	*create_block(t_uint bool_to_next, t_uint split_index)
{
	t_block	*new;

	new = (t_block *)g_shx->gc->malloc(sizeof(t_block), true);
	if (!new)
		return (NULL);
	new->ppl = NULL;
	new->next = NULL;
	new->bool_to_next = bool_to_next;
	new->split_index = split_index;
	return (new);
}

t_block	*add_block(t_block **block, t_uint bool_to_next, t_uint split_index)
{
	t_block	*new;
	t_block	*tmp;

	new = create_block(bool_to_next, split_index);
	if (!new)
		return (NULL);
	if (!*block)
		*block = new;
	else
	{
		tmp = *block;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}
