/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:12:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/22 16:19:44 by bfaure           ###   ########lyon.fr   */
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
	status = add_env_to_lst(shx, envp);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	status = create_s_env(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	status = check_env(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	status = lst_to_tab(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	shx->lst_paths = get_path(shx, shx->envp);
	shx->home = expand(shx, "HOME", ft_strlen("HOME"));
	shx->histfile = ft_strjoin(shx, shx->home, HIST_FILE);
	if (!shx->home || !shx->home[0])
		shx->histfile = DEF_HIST;
	return (CONTINUE_PROC);
}
