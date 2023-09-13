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
	t_uint			i;
	t_sh_context	*shx;
	t_uint			status;

	status = 0;
	shx = (*_cmd)->shx;
	i = 1;
	if (!(*_cmd)->cmd[1])
		return (NULL_DATA);
	else
	{
		while ((*_cmd)->cmd[i])
		{
			status |= lst_remove(shx, &shx->envx, lst_get_index(&shx->envx,
						(*_cmd)->cmd[i], ft_strlen((*_cmd)->cmd[i])));
			status |= lst_remove(shx, &shx->envp, lst_get_index(&shx->envp,
						(*_cmd)->cmd[i], ft_strlen((*_cmd)->cmd[i])));
			i++;
		}
	}
	status |= index_list_value(&shx->envp);
	status |= index_list_value(&shx->envx);
	return (status);
}
