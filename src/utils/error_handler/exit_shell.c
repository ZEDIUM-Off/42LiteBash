/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:21:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:39:50 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	exit_shell(t_uint error_code, char *msg)
{
	// trace("EXIT", "exit minishell", END);
	printf("MINISHELL %d : %s\n", error_code, msg);
	// log_action();
	gc_free_all();
	exit(error_code);
}
