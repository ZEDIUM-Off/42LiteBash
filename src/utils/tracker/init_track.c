/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 14:26:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	init_track(t_sh_context *shx)
{
	t_tracker	*tk;

	tk = (t_tracker *)malloc(sizeof(t_tracker));
	tk->step_nb = 0;
	tk->step_type = INIT_TRACK;
	tk->step_name = new_str(shx, "init_track");
	tk->current_func = new_str(shx, "init_track");
	tk->next = NULL;
	shx->tk = tk;
}
