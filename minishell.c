/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/01 14:25:02 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	g_exit_status;

int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;
	t_uint			status;

	g_exit_status = 0;
	status = init_shell(&ctx, envp, argv, argc);
	if (status != CONTINUE_PROC)
		return (exit_shell(&ctx), status);
	while (status != EXIT_SHELL)
		status = prompt(&ctx);
	if (status == EXIT_SHELL)
		return (exit_shell(&ctx), status);
}
