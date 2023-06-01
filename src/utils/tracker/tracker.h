#ifndef TRACKER_H
# define TRACKER_H

#include <minish.h>

struct s_tracker
{
	t_uint	step_nb;
	t_uint	step_type;
	t_str		step_name;
	t_str		current_func;
	t_tracker	*next;
};

void	trace(t_str func_name, t_str step_name, t_uint step_type);

#endif