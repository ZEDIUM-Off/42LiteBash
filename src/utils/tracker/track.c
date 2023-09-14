/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:11:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 18:36:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	trace(
	t_sh_context *shx, t_str func_name, t_str step_name, t_uint step_type)
{
	t_tracker	*new_tracker;

	new_tracker = (t_tracker *)malloc(sizeof(t_tracker));
	if (!new_tracker)
		return (handle_error(MALLOC_FAIL, NULL));
	new_tracker->step_nb = shx->tk->step_nb + 1;
	new_tracker->step_type = step_type;
	new_tracker->step_name = new_str(shx, step_name);
	new_tracker->current_func = new_str(shx, func_name);
	new_tracker->next = shx->tk;
	shx->tk = new_tracker;
	return (CONTINUE_PROC);
}
