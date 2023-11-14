/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:21:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/14 11:30:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	set_exit_status(t_uint	error_code)
{
	if (error_code == EXIT_TOO_ARG || error_code == EXPORT_NOT_VALID_ID
		|| error_code == CD_FAIL)
		g_exit_status = 1;
	if (error_code == SYNTAX_ERROR)
		g_exit_status = 2;
	if (error_code == IS_DIR || error_code == NO_PERM
		|| (error_code == OPEN_FAIL && (errno == EISDIR || errno == EACCES)))
		g_exit_status = 126;
	if (error_code == CMD_NOT_FOUND)
		g_exit_status = 127;
	if (error_code == EXIT_ARG)
		g_exit_status = 255;
}

void	exit_shell(t_sh_context *shx)
{
	gc_free_all(shx);
	exit(g_exit_status);
}
