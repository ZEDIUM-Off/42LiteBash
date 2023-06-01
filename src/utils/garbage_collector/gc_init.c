#include <minish.h>

int	gc_init(t_garbage_collector	*gc)
{
	gc->free = gc_free;
	gc->malloc = gc_malloc;
	gc->ptrs = NULL;
	gc->nb_ptrs = 0;
	return (1);
}