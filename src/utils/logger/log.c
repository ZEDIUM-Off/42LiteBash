/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/08 12:37:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	log_action(void)
{
	t_tracker			*tk;
	t_garbage_collector	*gc;

	tk = g_shx->tk;
	gc = g_shx->gc;
	printf("============== loging step %d: %s ==================\n", tk->step_nb, tk->step_name);
	printf("step type: %d\n", tk->step_type);
	printf("current function: [%s]\n", tk->current_func);
	printf("nb of pointers: %d\n", gc->nb_ptrs);
	printf("last pointer allocated : %p, size: %d, allocated in func: %s at step : %d\n", gc->ptrs->ptr, gc->ptrs->size, gc->ptrs->allocated_in.current_func, gc->ptrs->allocated_in.step_nb);
	printf("====================================================\n\n");
}
