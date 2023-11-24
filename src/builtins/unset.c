/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:04:58 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/21 14:04:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	unset_remove(t_sh_context *shx, t_cmd **_cmd,
	t_uint i)
{
	int			index;
	t_uint		status;

	status = check_var (shx, (*_cmd)->cmd[i], NULL, UNSET_BI);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	index = env_get_index(&shx->env, (*_cmd)->cmd[i]);
	if (index != -1)
	{
		status = lst_remove(shx, &shx->env, index);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	unset_cmd(t_cmd **_cmd)
{
	t_sh_context	*shx;
	t_uint			i;
	t_uint			status;

	shx = (*_cmd)->shx;
	i = 1;
	if (!(*_cmd)->cmd[1])
		return (CONTINUE_PROC);
	else
	{
		while ((*_cmd)->cmd[i])
		{
			status = unset_remove(shx, _cmd, i);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			i++;
		}
	}
	return (CONTINUE_PROC);
}
