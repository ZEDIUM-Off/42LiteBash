/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:12:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/20 17:52:44 by bfaure           ###   ########lyon.fr   */
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
	printf("PASS 1\n");
	status = create_s_env(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	printf("PASS 2\n");
	status = check_env(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	printf("PASS 3\n");
	shx->lst_paths = get_path(shx, envp);
	if (!shx->lst_paths)
		return (handle_error(MALLOC_FAIL, NULL));
	printf("PASS 4\n");
	status = add_env_to_lst(shx, envp);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	printf("PASS 5\n");
	shx->home = expand(shx, "HOME", ft_strlen("HOME"));
	shx->histfile = ft_strjoin(shx, shx->home, HIST_FILE);
	return (CONTINUE_PROC);
}
