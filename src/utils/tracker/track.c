/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:11:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 11:45:17 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	trace(t_str func_name, t_str step_name, t_uint step_type)
{
	t_tracker	new_tracker;

	new_tracker.step_nb = g_shx->tk->step_nb + 1;
	new_tracker.step_type = step_type;
	new_tracker.step_name = new_str(step_name);
	printf("new_tracker.step_name = %s\n", new_tracker.step_name);
	new_tracker.current_func = new_str(func_name);
	new_tracker.next = g_shx->tk;
	g_shx->tk = &new_tracker;
}
