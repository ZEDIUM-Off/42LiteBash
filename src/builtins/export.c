/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/18 16:59:23 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <minish.h>

// t_uint	export_cmd(t_cmd **_cmd)
// {
// 	t_uint			index;
// 	t_sh_context	*shx;
// 	t_uint			status;

// 	shx = (*_cmd)->shx;
// 	index = lst_get_last(&shx->envp)->index + 1;
// 	if (!(*_cmd)->cmd[1])
// 		status = lst_print(&shx->envx, "declare -x %u %s\n");
// 	else
// 		status = check_export_return((_cmd), index);
// 	if (status != CONTINUE_PROC)
// 		return (handle_error(status, NULL));
// 	return (sort_env_export(shx), status);
// }
