/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:12:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:39:50 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	init_shell(
	t_sh_context *shx,
	t_str *envp,
	t_str *argv,
	int argc
)
{
	init_sh_context(shx, argv, argc);
	set_ctx(shx);
	init_gc();
	init_track();
	g_shx->env = envp;
	g_shx->lst_paths = get_path(envp);
	g_shx->envp = add_env_to_lst(envp);
	g_shx->envx = add_env_to_lst(envp);
	check_envp();
	check_envx();
	sort_env_export();
	// log_action();
}
