/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/18 10:56:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	handle_sigint(int sig)
{
	(void)sig;
	printf("\n");
}

void	handle_sigquit(int sig)
{
	(void)sig;
	printf("Quit: 3\n");
}

void	handle_sigchld(int sig)
{
	int		status;
	pid_t	pid;

	pid = waitpid(-1, &status, WNOHANG);
	if (pid > 0)
		printf("Le processus enfant %d a terminé avec le signal : %d\n", pid, sig);
}

void handle_eof(int sig)
{
	(void)sig;
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

