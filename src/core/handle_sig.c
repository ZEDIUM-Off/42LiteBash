/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 12:31:19 by  mchenava        ###   ########.fr       */
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

void	handle_sigint_child(int sig)
{
	(void)sig;
	printf("\n");
}

void	handle_sigstp(int sig)
{
	printf("sigstp: %d\n", sig);
}

void	hd_sig(int sig)
{
	printf("\n");
	if (sig == SIGINT)
		g_exit_status = 130;
	else if (sig == SIGQUIT)
		g_exit_status = 131;
	exit (g_exit_status);
}

void	handle_sigquit(int sig)
{
	(void)sig;
	g_exit_status = 131;
	printf("\n");
}
