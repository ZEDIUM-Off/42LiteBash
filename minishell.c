/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/09 13:50:48 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_sh_context *g_shx;

int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;

	init_shell(&ctx, envp, argv, argc);
	trace("main", "start", START);
	t_str test = new_str("test");
	(void)test;
	g_shx->lst_paths = get_path(envp);
	lst_print(&g_shx->lst_paths, "lst_paths %s\n");
	prompt(envp);
	log_action();
	return (0);
}
