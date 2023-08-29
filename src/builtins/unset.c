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

t_uint	unset_cmd(t_cmd **_cmd)
{
	t_uint	i;

	trace("unset_cmd", "cmd unset", EXEC);
	i = 1;
	if (!(*_cmd)->cmd[1])
		return (0);
	else
	{
		while ((*_cmd)->cmd[i])
		{
			lst_remove(&g_shx->envx, lst_get_index(&g_shx->envx,
					(*_cmd)->cmd[i], ft_strlen((*_cmd)->cmd[i])));
			lst_remove(&g_shx->envp, lst_get_index(&g_shx->envp,
					(*_cmd)->cmd[i], ft_strlen((*_cmd)->cmd[i])));
			i++;
		}
	}
	index_list_value(&g_shx->envp);
	index_list_value(&g_shx->envx);
	log_action();
	return (0);
}
