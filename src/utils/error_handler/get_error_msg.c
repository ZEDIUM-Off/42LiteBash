/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:43:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/25 14:51:59 by  mchenava        ###   ########.fr       */
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
	else if (error_code == INVALID_META)
		return (INVALID_META_MSG);
	else if (error_code == UNCLOSED_QUOTES)
		return (UNCLOSED_QUOTES_MSG);
	else if (error_code == EXPORT_NOT_VALID_ID)
		return (EXPORT_NOT_VALID_ID_MSG);
	else if (error_code == EXIT_ARG)
		return (EXIT_ARG_MSG);
	else if (error_code == EXIT_TOO_ARG)
		return (EXIT_TOO_ARG_MSG);
	else if (error_code == IS_DIR)
		return (IS_DIR_MSG);
	return (NO_ERROR_MSG);
}
