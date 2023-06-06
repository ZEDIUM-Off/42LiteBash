/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:33:02 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 11:33:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	init_gc(t_garbage_collector	*gc)
{
	gc->free = gc_free;
	gc->malloc = gc_malloc;
	gc->ptrs = NULL;
	gc->nb_ptrs = 0;
	return (1);
}

void	set_gc(t_garbage_collector *gc)
{
	g_shx->gc = gc;
}
