/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:32:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 11:38:07 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <minish.h>

struct s_garbage_collector
{
	t_free_func			free;
	t_malloc_func		malloc;
	t_ptr				*ptrs;
	int					nb_ptrs;
};

struct s_ptr
{
	int				id;
	t_uint			size;
	void			*ptr;
	t_ptr			*next;
	t_tracker		allocated_in;
};

void	*gc_malloc(size_t size);
void	gc_free(void *ptr);
void	set_gc(t_garbage_collector *gc);
int		init_gc(t_garbage_collector	*gc);

#endif