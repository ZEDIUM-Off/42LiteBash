/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:43:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/14 01:44:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	get_error_msg(t_uint error_code)
{
	if (error_code == MALLOC_FAIL)
		return (MALLOC_FAIL_MSG);
	else if (error_code == PIPE_FAIL)
		return (PIPE_FAIL_MSG);
	else if (error_code == FORK_FAIL)
		return (FORK_FAIL_MSG);
	else if (error_code == EXECVE_FAIL)
		return (EXECVE_FAIL_MSG);
	else if (error_code == WAITPID_FAIL)
		return (WAITPID_FAIL_MSG);
	else if (error_code == PROC_NOT_TERMINATED)
		return (PROC_NOT_TERMINATED_MSG);
	else if (error_code == NULL_DATA)
		return (NULL_DATA_MSG);
	else if (error_code == SYNTAX_ERROR)
		return (SYNTAX_ERROR_MSG);
	else if (error_code == NO_FILE_DIR)
		return (NO_FILE_DIR_MSG);
	else if (error_code == CMD_NOT_FOUND)
		return (CMD_NOT_FOUND_MSG);
	else if (error_code == CLOSE_FAIL)
		return (CLOSE_FAIL_MSG);
	else if (error_code == DUP_FAIL)
		return (DUP_FAIL_MSG);
	return (NO_ERROR_MSG);
}