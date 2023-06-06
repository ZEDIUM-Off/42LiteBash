/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 11:11:08 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	init_track(t_tracker *tk)
{
	tk->step_nb = 0;
	tk->step_type = INIT_TRACK;
	tk->step_name = new_str("init_track");
	tk->current_func = new_str("init_track");
	tk->next = NULL;
}

void	set_track(t_tracker *_tk)
{
	g_shx->tk = _tk;
}
