/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:12:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/10 11:39:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	init_signals(void)
{
	signal(SIGQUIT, handle_sigquit);
	// signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, handle_sigint);
}

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
	status = add_env_to_lst(shx, envp);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	lst_print(&shx->envp, "envp : %s\n");
	lst_print(&shx->envx, "envx : %s\n");
	init_signals();
	return (CONTINUE_PROC);
}
