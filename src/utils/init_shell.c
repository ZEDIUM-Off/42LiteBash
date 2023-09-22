/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:12:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/22 16:03:33 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	init_shell(
	t_sh_context *shx,
	t_str *envp,
	t_str *argv,
	int argc
)
{
	t_uint	status;

	init_sh_context(shx, argv, argc, envp);
	status = init_gc(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = init_track(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	shx->lst_paths = get_path(shx, envp);
	if (!shx->lst_paths)
		return (handle_error(MALLOC_FAIL, NULL));
	status = add_env_to_lst(shx, shx->envp, envp);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	lst_print(&shx->envp, "envp");
	status = add_env_to_lst(shx, shx->envx, envp);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	lst_print(&shx->envx, "envx");
	// status = create_s_env(shx);
	// if (status != CONTINUE_PROC)
	// 	return (handle_error(status, NULL));
	// status = check_env(shx);
	// if (status != CONTINUE_PROC)
	// 	return (handle_error(status, NULL));
	// status = create_s_env(shx);
	// if (status != CONTINUE_PROC)
	// 	return (handle_error(status, NULL));
	// status = check_envx(shx);
	// if (status != CONTINUE_PROC)
	// 	return (handle_error(status, NULL));
	// sort_env_export(shx);
	return (CONTINUE_PROC);
}
