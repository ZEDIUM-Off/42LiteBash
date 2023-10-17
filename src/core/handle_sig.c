/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/10 11:42:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	handle_sigint(int sig)
{
	g_signal = sig;
	printf("sigint: %d\n", sig);
	printf("\n");
	rl_set_prompt("$>");
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int sig)
{
	g_signal = sig;
	printf("sigquit: %d\n", sig);
	printf("exit\n");
}

void	handle_sigchld(int sig)
{
	int		status;
	pid_t	pid;

	pid = waitpid(-1, &status, WNOHANG);
	if (pid > 0)
		printf("Le processus \
			enfant %d a terminé avec le signal : %d\n", pid, sig);
}

void	handle_eof(int sig)
{
	g_signal = sig;
	printf("exit\n");
	// exit_shell(EXIT_SUCCESS);
}
