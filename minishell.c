/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/04 10:42:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>


int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;

	init_shell(&ctx, envp, argv, argc);
	//trace(&ctx, "main", "start", START);
	t_str test = new_str(&ctx, "test");
	(void)test;
	// lst_print(&g_shx->lst_paths, "lst_paths %s\n");
	// lst_print(&g_shx->envp, "lst envp %s\n");
	prompt(&ctx, envp);
	//log_action(&ctx);
	return (0);
}
