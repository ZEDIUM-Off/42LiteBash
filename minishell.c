/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 13:14:52 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;

	init_shell(&ctx, envp, argv, argc);
	//trace("main", "start", START);
	prompt();
	return (0);
}
