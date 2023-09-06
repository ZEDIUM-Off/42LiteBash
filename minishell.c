/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/06 19:49:38 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>


int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;
	t_uint			status;

	status = 0;
	status += init_shell(&ctx, envp, argv, argc);
	if (status > 0)
		return (exit_shell(&ctx, status, "init_shell ERROR"), status);

	// lst_print(&g_shx->lst_paths, "lst_paths %s\n");
	// lst_print(&g_shx->envp, "lst envp %s\n");
	prompt(&ctx, envp);
}
