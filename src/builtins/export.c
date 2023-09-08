/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/08 15:43:59 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	export_cmd_add_to_lst(t_cmd **_cmd, t_uint i, t_uint index)
{
	t_str			argv;
	t_str			argb;
	t_sh_context	*shx;
	t_uint			status;

	status = 0;
	shx = (*_cmd)->shx;
	trace(shx, "export_cmd_add_to_lst", "add to lst the export var", EXEC);
	argv = ft_strdup(shx, (*_cmd)->cmd[i]);
	if (!argv)
		return (MALLOC_FAIL);
	argb = ft_strdup_char(shx, (*_cmd)->cmd[i], '=');
	if (!argb)
		return (MALLOC_FAIL);
	if ((*_cmd)->chunk)
	{
		argv = ft_strfjoin(shx, argv, (*_cmd)->chunk->txt[0]);
		if (!argv)
			return (MALLOC_FAIL);
	}
	if (!lst_get_index(&shx->envx, argb, ft_strlen_to_char(argv, '=')))
		status |= lst_add_back(shx, &shx->envx, argv, index);
	else
		status |= lst_remplace(shx, &shx->envx, lst_get_index(&shx->envx, argb,
					ft_strlen_to_char(argv, '=')), argv);
	if (!lst_get_index(&shx->envp, argb, ft_strlen_to_char(argv, '='))
		&& ft_strchr(argv, '=') != NULL)
		status |= lst_add_back(shx, &shx->envp, argv, index);
	else if (ft_strchr(argv, '=') != NULL)
		status |= lst_remplace(shx, &shx->envp, lst_get_index(&shx->envp, argb,
					ft_strlen_to_char(argv, '=')), argv);
	log_action(shx);
	return (shx->gc->free(shx, argb), status);
}

t_uint	export_cmd(t_cmd **_cmd)
{
	t_uint			i;
	t_uint			index;
	t_sh_context	*shx;
	t_uint			status;

	status = 0;
	shx = (*_cmd)->shx;
	trace(shx, "export_cmd", "cmd export", EXEC);
	index = lst_get_last(&shx->envp)->index + 1;
	i = 1;
	if (!(*_cmd)->cmd[1])
		status |= lst_print(&shx->envx, "declare -x %u %s\n");
	else
	{
		while ((*_cmd)->chunk || (*_cmd)->cmd[i])
		{
			status |= export_cmd_add_to_lst((_cmd), i, index);
			if (status > 0)
				return (status);
			index++;
			if ((*_cmd)->chunk)
				i = (*_cmd)->chunk->end;
			i++;
			if ((*_cmd)->chunk)
				(*_cmd)->chunk = (*_cmd)->chunk->next;
		}
	}
	printf("status = %u\n", status);
	log_action(shx);
	return (sort_env_export(shx), status);
}
