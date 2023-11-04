/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:12:08 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/04 10:12:08 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

// t_uint	export_cmd(t_cmd **_cmd)
// {
// 	t_export	to_export;
// 	t_uint		i;
// 	t_uint		status;
// 	t_chunk		*chunk;
	
// 	i = 1;
// 	chunk = (*_cmd)->chunk;
// 	status = CONTINUE_PROC;
// 	if (!(*_cmd)->cmd[1])
// 		lst_print(&(*_cmd)->shx->envx, "declare -x %s\n");
// 	while ((*_cmd)->cmd[i])
// 	{
// 		init_export((*_cmd)->shx, &to_export);
// 		if (chunk && chunk->start == i + 1)
// 			status = handle_chunk_var(&chunk, _cmd, &to_export, &i);
// 		else if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i][0] != '+'
// 			&& (*_cmd)->cmd[i][0] != '=')
// 			status = handle_var(_cmd, &chunk, &to_export, &i);
// 		if (status != CONTINUE_PROC)
// 			return (handle_error(status, NULL));
// 		printf ("cmd[%d] = %s\n", i, (*_cmd)->cmd[i]);
// 		if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i + 1]
// 			&& ((*_cmd)->cmd[i + 1][0] == '+' || (*_cmd)->cmd[i + 1][0] == '='))
// 			status = handle_plus_equal(_cmd, &chunk, &to_export, &i);
// 		if (status != CONTINUE_PROC)
// 			return (handle_error(status, NULL));
// 		printf ("exp cmd[%d] = %s\n", i, (*_cmd)->cmd[i]);
// 		status = export((*_cmd)->shx, &to_export);
// 		if (status != CONTINUE_PROC)
// 			return (handle_error(status, NULL));
// 	}
// 	return (CONTINUE_PROC);
// }

void	init_export_cmd(t_cmd **_cmd, t_export *to_export, t_uint *i, t_chunk **chunk)
{
	*i = 1;
	*chunk = (*_cmd)->chunk;
	if (!(*_cmd)->cmd[1])
		lst_print(&(*_cmd)->shx->envx, "declare -x %s\n");
	init_export((*_cmd)->shx, to_export);
}

t_uint	handle_cmd_chunk(t_cmd **_cmd, t_export *to_export, t_uint *i, t_chunk **chunk)
{
	t_uint status = CONTINUE_PROC;
	if (*chunk && (*chunk)->start == *i + 1)
		status = handle_chunk_var(chunk, _cmd, to_export, i);
	else if ((*_cmd)->cmd[*i] && (*_cmd)->cmd[*i][0] != '+'
		&& (*_cmd)->cmd[*i][0] != '=')
		status = handle_var(_cmd, chunk, to_export, i);
	return status;
}

t_uint	process_plus_equal_cmd(t_cmd **_cmd, t_export *to_export, t_uint *i, t_chunk **chunk)
{
	t_uint status = CONTINUE_PROC;
	if ((*_cmd)->cmd[*i] && (*_cmd)->cmd[*i + 1]
		&& ((*_cmd)->cmd[*i + 1][0] == '+' || (*_cmd)->cmd[*i + 1][0] == '='))
		status = handle_plus_equal(_cmd, chunk, to_export, i);
	return status;
}

t_uint	export_cmd(t_cmd **_cmd)
{
	t_export	to_export;
	t_uint		i;
	t_uint		status;
	t_chunk		*chunk;

	init_export_cmd(_cmd, &to_export, &i, &chunk);
	while ((*_cmd)->cmd[i])
	{
		status = handle_cmd_chunk(_cmd, &to_export, &i, &chunk);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = process_plus_equal_cmd(_cmd, &to_export, &i, &chunk);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = export((*_cmd)->shx, &to_export);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}