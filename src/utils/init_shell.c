/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:12:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/14 01:56:11 by  mchenava        ###   ########.fr       */
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
	init_track(shx);
	shx->lst_paths = get_path(shx, envp);
	status = add_env_to_lst(shx, shx->envp, envp);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	status = add_env_to_lst(shx, shx->envx, envp);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	status = create_s_env(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = check_env(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = create_s_env(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	// status = check_envx(shx);
	// if (status != CONTINUE_PROC)
	// 	return (handle_error(status, NULL));
	// sort_env_export(shx);
	// status = index_list_value(&shx->envx);
	// if (status != CONTINUE_PROC)
	// 	return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
