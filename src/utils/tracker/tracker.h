/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:07:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 19:00:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACKER_H
# define TRACKER_H

# include <minish.h>

struct s_tracker
{
	t_uint		step_nb;
	t_uint		step_type;
	t_str		step_name;
	t_str		current_func;
	t_tracker	*next;
};

t_uint	trace(
			t_sh_context *shx, t_str func_name,
			t_str step_name, t_uint step_type);
t_uint	init_track(t_sh_context *shx);

#endif