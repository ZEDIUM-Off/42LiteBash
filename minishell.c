/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/13 19:02:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;
	t_uint			status;

	status = init_shell(&ctx, envp, argv, argc);
	if (status != CONTINUE_PROC)
		return (exit_shell(&ctx, status, "init_shell ERROR"), status);
	status = prompt(&ctx, envp);
	if (status != CONTINUE_PROC)
		return (exit_shell(&ctx, status, "prompt ERROR"), status);
}
