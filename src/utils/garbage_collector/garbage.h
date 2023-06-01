#ifndef GARBAGE_H
# define GARBAGE_H

#include <minish.h>

struct s_garbage_collector
{
	t_free_func	free;
	t_malloc_func	malloc;
	t_ptr	*ptrs;
	int		nb_ptrs;
};

struct s_ptr
{
	int			id;
	t_uint	size;
	void		*ptr;
	t_ptr		*next;
	t_str		allocated_in;
};

void	*gc_malloc(size_t size);
void	gc_free(void *ptr);
void	set_garbage_collector(t_garbage_collector *gc);
int		gc_init(t_garbage_collector	*gc);

#endif