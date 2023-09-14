/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:33:02 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 18:58:07 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	init_gc(t_sh_context *shx)
{
	t_garbage_collector	*gc;

	gc = (t_garbage_collector *)malloc(sizeof(t_garbage_collector));
	if (!gc)
		return (handle_error(MALLOC_FAIL, NULL));
	gc->free = gc_free;
	gc->malloc = gc_malloc;
	gc->ptrs = NULL;
	gc->nb_ptrs = 0;
	shx->gc = gc;
	return (CONTINUE_PROC);
}
