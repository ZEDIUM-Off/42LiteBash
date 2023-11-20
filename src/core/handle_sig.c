/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/20 17:30:57 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	handle_sigint(int sig)
{
	(void)sig;
	g_exit_status = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_sigstp(int sig)
{
	printf("sigstp: %d\n", sig);
}

void	handle_sigchld(int sig)
{
	printf ("sigchld: %d\n", sig);
}

void	handle_sigquit(int sig)
{
	(void)sig;
	g_exit_status = 131;
	printf("\n");
}
