/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 14:59:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	init_track(void)
{
	t_tracker	*tk;

	tk = (t_tracker *)malloc(sizeof(t_tracker));
	tk->step_nb = 0;
	tk->step_type = INIT_TRACK;
	tk->step_name = new_str("init_track");
	tk->current_func = new_str("init_track");
	tk->next = NULL;
	g_shx->tk = tk;
}
