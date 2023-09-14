/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:31:48 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/05 12:31:48 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_s_env(t_sh_context *shx)
{
	if (!shx->s_env)
		shx->s_env = (t_status_env *)shx->gc->malloc(shx,
					sizeof(t_status_env), true);
	if (!shx->s_env)
		return (handle_error(MALLOC_FAIL, NULL));
	shx->s_env->old_pwd = 0;
	shx->s_env->pwd = 0;
	shx->s_env->shlvl = 0;
	return (CONTINUE_PROC);
}
