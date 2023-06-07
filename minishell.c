/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:51 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/07 15:13:26 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_sh_context	*g_shx;

int	main(int argc, char **argv, char **envp)
{
	t_sh_context	ctx;

	init_shell(&ctx, envp, argv, argc);
	trace("main", "start", START);
	t_str test = new_str("test");
	log_action();
	(void)test;
	prompt();
	return (0);
}
