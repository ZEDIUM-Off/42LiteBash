/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:11:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:31:42 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	trace(
	t_sh_context *shx, t_str func_name, t_str step_name, t_uint step_type)
{
	t_tracker	*new_tracker;

	new_tracker = (t_tracker *)malloc(sizeof(t_tracker));
	if (!new_tracker)
		exit_shell(shx,
			TRACKER_ALLOC_ERROR, "failed to allocate a tracker node");
	new_tracker->step_nb = shx->tk->step_nb + 1;
	new_tracker->step_type = step_type;
	new_tracker->step_name = new_str(shx, step_name);
	new_tracker->current_func = new_str(shx, func_name);
	new_tracker->next = shx->tk;
	shx->tk = new_tracker;
}
