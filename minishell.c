/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/24 14:41:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;
	t_uint			status;

	g_exit_status = 0;
	status = init_shell(&ctx, envp, argv, argc);
	if (status != CONTINUE_PROC)
		return (exit_shell(&ctx, status), status);
	while (status != EXIT_SHELL)
		status = prompt(&ctx);
	if (status == EXIT_SHELL)
		return (exit_shell(&ctx, status), status);
}
