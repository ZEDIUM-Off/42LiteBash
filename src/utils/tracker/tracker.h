/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:07:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 11:31:54 by  mchenava        ###   ########.fr       */
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

void	trace(t_str func_name, t_str step_name, t_uint step_type);
void	init_track(t_tracker *tk);
void	set_track(t_tracker *tk);

#endif