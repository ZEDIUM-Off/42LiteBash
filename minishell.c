/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/04 11:44:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>


int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;

	init_shell(&ctx, envp, argv, argc);

	// lst_print(&g_shx->lst_paths, "lst_paths %s\n");
	// lst_print(&g_shx->envp, "lst envp %s\n");
	prompt(&ctx, envp);
}
