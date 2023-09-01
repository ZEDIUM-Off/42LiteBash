/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:37:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:31:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	*gc_malloc(t_sh_context *shx, size_t size, bool count)
{
	t_ptr				*new_ptr;
	t_garbage_collector	*gc;

	new_ptr = malloc(sizeof(t_ptr));
	if (!new_ptr)
		exit_shell(shx,
			GARB_ALLOC_ERROR, "failed to allocate a gc node");
	new_ptr->ptr = malloc(size);
	if (!new_ptr->ptr)
		return (NULL);
	gc = shx->gc;
	new_ptr->size = size;
	new_ptr->counted = count;
	if (shx->tk)
		new_ptr->allocated_in = *(shx->tk);
	new_ptr->next = NULL;
	if (!gc->ptrs)
		gc->ptrs = new_ptr;
	else
	{
		new_ptr->next = gc->ptrs;
		gc->ptrs = new_ptr;
	}
	if (count)
		gc->nb_ptrs++;
	return (new_ptr->ptr);
}

void	gc_free(t_sh_context *shx, void *ptr)
{
	t_ptr				*ptrs;
	t_ptr				*tmp;
	t_ptr				*top;
	t_garbage_collector	*gc;

	gc = shx->gc;
	ptrs = gc->ptrs;
	top = ptrs;
	while (ptrs)
	{
		if (ptrs->ptr == ptr)
		{
			tmp = ptrs;
			free(tmp->ptr);
			if (ptrs->counted)
				gc->nb_ptrs--;
			ptrs = ptrs->next;
		}
		ptrs = ptrs->next;
	}
	gc->ptrs = top;
}

void	gc_free_all(t_sh_context *shx)
{
	t_ptr				*ptrs;
	t_ptr				*tmp;
	t_ptr				*top;
	t_garbage_collector	*gc;

	gc = shx->gc;
	ptrs = gc->ptrs;
	top = ptrs;
	while (ptrs)
	{
		tmp = ptrs;
		free(tmp->ptr);
		if (ptrs->counted)
			gc->nb_ptrs--;
		ptrs = ptrs->next;
	}
	gc->ptrs = top;
}
