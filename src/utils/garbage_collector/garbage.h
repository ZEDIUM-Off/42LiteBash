/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:32:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/14 10:09:46 by  mchenava        ###   ########.fr       */
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
	t_uint			size;
	void			*ptr;
	t_ptr			*next;
	t_tracker		allocated_in;
	bool			counted;
};

void	*gc_malloc(size_t size, bool count);
void	gc_free(void *ptr);
void	init_gc(void);

#endif