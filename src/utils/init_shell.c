/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:12:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/08 14:31:24 by bfaure           ###   ########lyon.fr   */
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

	status = 0;
	init_sh_context(shx, argv, argc, envp);
	init_gc(shx);
	init_track(shx);
	shx->lst_paths = get_path(shx, envp);
	shx->envp = add_env_to_lst(shx, envp);
	shx->envx = add_env_to_lst(shx, envp);
	status |= create_s_env(shx);
	status |= check_env(shx);
	status |= create_s_env(shx);
	status |= check_envx(shx);
	sort_env_export(shx);
	status |= index_list_value(&shx->envx);
	return (status);
	//log_action(shx);
}
