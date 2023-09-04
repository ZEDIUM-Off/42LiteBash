/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:12:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/04 10:42:52 by  mchenava        ###   ########.fr       */
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
	init_sh_context(shx, argv, argc, envp);
	init_gc(shx);
	init_track(shx);
	shx->lst_paths = get_path(shx, envp);
	shx->envp = add_env_to_lst(shx, envp);
	shx->envx = add_env_to_lst(shx, envp);
	sort_env_export(shx);
	check_env(shx);
	//log_action(shx);
}
