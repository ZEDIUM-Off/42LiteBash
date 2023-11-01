/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:55:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/22 08:37:16 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	export(t_sh_context *shx, t_export *to_export)
{
	t_uint	status;
	int		index;
	t_str	tmp;

	tmp = NULL;
	index = env_get_index(shx, &shx->envx, to_export->name);
	status = CONTINUE_PROC;
	if (to_export->type == PLUS_EQUAL && index != -1)
		tmp = lst_get(&shx->envx, index);
	status = build_var(shx, to_export, tmp);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (index == -1)
	{
		if (to_export->type == NONE)
			lst_add_back(shx, &shx->envx, ft_strdup(shx, to_export->name));
		else
			lst_add_back(shx, &shx->envx, ft_strdup(shx, to_export->builded));
	}
	else if (to_export->type != NONE)
		lst_set(&shx->envx, index, ft_strdup(shx, to_export->builded));
	return (status);
}

t_uint	export_cmd(t_cmd **_cmd)
{
	t_export	to_export;
	t_uint		i;
	t_uint		status;
	t_chunk		*chunk;
	
	i = 1;
	chunk = (*_cmd)->chunk;
	status = CONTINUE_PROC;
	if (!(*_cmd)->cmd[1])
		lst_print(&(*_cmd)->shx->envx, "declare -x %s\n");
	while ((*_cmd)->cmd[i])
	{
		init_export((*_cmd)->shx, &to_export);
		if (chunk && chunk->start == i + 1)
			status = handle_chunk_var(&chunk, _cmd, &to_export, &i);
		else if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i][0] != '+'
			&& (*_cmd)->cmd[i][0] != '=')
			status = handle_var(_cmd, &chunk, &to_export, &i);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		printf ("cmd[%d] = %s\n", i, (*_cmd)->cmd[i]);
		if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i + 1]
			&& ((*_cmd)->cmd[i + 1][0] == '+' || (*_cmd)->cmd[i + 1][0] == '='))
			status = handle_plus_equal(_cmd, &chunk, &to_export, &i);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		printf ("exp cmd[%d] = %s\n", i, (*_cmd)->cmd[i]);
		status = export((*_cmd)->shx, &to_export);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}
