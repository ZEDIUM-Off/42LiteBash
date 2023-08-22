/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/22 12:50:30 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	export_cmd(t_cmd **_cmd)
{
	t_uint	i;
	t_str	argv;
	t_uint	index;
	
	trace("export_cmd", "cmd export", EXEC);
	index = lst_get_last(&g_shx->envp)->index + 1;
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
			if (!lst_get_index(&g_shx->envx, argv, ft_strlen_to_char(argv, '=')))
				lst_add_back(&g_shx->envx, argv, index);
			if (!lst_get_index(&g_shx->envp, argv, ft_strlen_to_char(argv, '='))
				&& ft_strchr(argv, '=') != NULL)
				lst_add_back(&g_shx->envp, argv, index);
			index++;
			if ((*_cmd)->chunk)
				i = (*_cmd)->chunk->end;
			i++;
			if ((*_cmd)->chunk)
				(*_cmd)->chunk = (*_cmd)->chunk->next;
		}
	}
	sort_env_export();
	log_action();
	return (0);
}
