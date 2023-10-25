/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/24 14:56:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	handle_sigint(int sig)
{
	(void)sig;
	printf("\n");
	exit(STOP_PROC);
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
	printf("sigquit: %d\n", sig);
}
