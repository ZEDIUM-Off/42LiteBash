/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:37:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 15:06:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	*gc_malloc(size_t size)
{
	t_ptr				*new_ptr;
	t_garbage_collector	*gc;

	new_ptr = malloc(sizeof(t_ptr));
	if (!new_ptr)
		exit_shell(GARB_ALLOC_ERROR, "failed to allocate a gc node");
	new_ptr->ptr = malloc(size);
	if (!new_ptr->ptr)
		return (NULL);
	gc = g_shx->gc;
	new_ptr->size = size;
	new_ptr->id = gc->nb_ptrs;
	if (g_shx->tk)
		new_ptr->allocated_in = *(g_shx->tk);
	new_ptr->next = NULL;
	if (!gc->ptrs)
		gc->ptrs = new_ptr;
	else
	{
		new_ptr->next = gc->ptrs;
		gc->ptrs = new_ptr;
	}
	gc->nb_ptrs++;
	return (new_ptr->ptr);
}

void	gc_free(void *ptr)
{
	t_ptr				*ptrs;
	t_ptr				*tmp;
	t_ptr				*top;
	t_garbage_collector	*gc;

	gc = g_shx->gc;
	ptrs = gc->ptrs;
	top = ptrs;
	while (ptrs)
	{
		if (ptrs->ptr == ptr)
		{
			tmp = ptrs;
			ptrs = ptrs->next;
			free(tmp->ptr);
			gc->nb_ptrs--;
		}
		ptrs = ptrs->next;
	}
	gc->ptrs = top;
}
