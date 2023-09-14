/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 18:59:13 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	init_track(t_sh_context *shx)
{
	t_tracker	*tk;

	tk = (t_tracker *)malloc(sizeof(t_tracker));
	if (!tk)
		return (handle_error(MALLOC_FAIL, NULL));
	tk->step_nb = 0;
	tk->step_type = INIT_TRACK;
	tk->step_name = new_str(shx, "init_track");
	if (!tk->step_name)
		return (handle_error(MALLOC_FAIL, NULL));
	tk->current_func = new_str(shx, "init_track");
	if (!tk->current_func)
		return (handle_error(MALLOC_FAIL, NULL));
	tk->next = NULL;
	shx->tk = tk;
	return (CONTINUE_PROC);
}
