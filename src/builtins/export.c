/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/17 17:44:21 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	export_cmd(t_cmd **_cmd)
{
	t_uint	i;
	t_str	argv;

	trace("export_cmd", "cmd export", EXEC);
	i = 1;
	if (!(*_cmd)->cmd[1])
		lst_print(&g_shx->envx, "lst envp %u %s\n");
	else
	{
		while ((*_cmd)->chunk || (*_cmd)->cmd[i])
		{
			argv = ft_strdup((*_cmd)->cmd[i]);
			if ((*_cmd)->chunk)
				argv = ft_strfjoin(argv, (*_cmd)->chunk->txt[0]);
			if (!lst_get_index(&g_shx->envx, argv))
				lst_add_back(&g_shx->envx, argv, 0);
			if (!lst_get_index(&g_shx->envp, argv)
				&& ft_strchr(argv, '=') != NULL)
				lst_add_back(&g_shx->envp, argv, 0);
			i = (*_cmd)->chunk->end;
			i++;
			(*_cmd)->chunk = (*_cmd)->chunk->next;
		}
	}
	sort_env_export();
	log_action();
	return ;
}
