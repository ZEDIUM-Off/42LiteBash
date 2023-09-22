/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:55:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/22 15:58:01 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	export_add(t_sh_context *shx, t_cmd **_cmd, t_uint i, t_uint status)
{
	(void)status;
	(void)shx;
	(void)_cmd;
	(void)i;
	(void)status;
	return (CONTINUE_PROC);
}

t_uint	export_cmd(t_cmd **_cmd)
{
	t_sh_context	*shx;
	t_uint			i;
	t_uint			status;

	shx = (*_cmd)->shx;
	status = SKIP_FORK;
	i = 1;
	if (!(*_cmd)->cmd[1])
		return (lst_print(&shx->envx, "declare -x\n"));
	else
	{
		while ((*_cmd)->cmd[i])
		{
			status = export_add(shx, _cmd, i, status);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			i++;
		}
	}
	return (CONTINUE_PROC);
}
