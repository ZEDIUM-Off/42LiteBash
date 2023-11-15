/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:32:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/15 11:26:52 by  mchenava        ###   ########.fr       */
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
	bool			counted;
};

void	*gc_malloc(t_sh_context *shx, size_t size, bool count);
void	gc_free(t_sh_context *shx, void *ptr);
void	gc_free_all(t_sh_context *shx);
t_uint	init_gc(t_sh_context *shx);

#endif