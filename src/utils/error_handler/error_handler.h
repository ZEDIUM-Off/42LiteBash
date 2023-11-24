/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:22:15 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/24 14:11:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <minish.h>

# define MALLOC_FAIL_MSG "memory allocation failed"
# define PIPE_FAIL_MSG "pipe creation failed"
# define FORK_FAIL_MSG "fork failed"
# define WAITPID_FAIL_MSG "waitpid failed"
# define NULL_DATA_MSG "null data found"
# define SYNTAX_ERROR_MSG "syntax error near unexpected token"
# define NO_FILE_DIR_MSG "No such file or directory"
# define NO_PERM_MSG "Permission denied"
# define CMD_NOT_FOUND_MSG "command not found"
# define DUP_FAIL_MSG "dup failed"
# define INVALID_META_MSG "syntax error near invalid token"
# define UNCLOSED_QUOTES_MSG "unclosed quotes"
# define EXPORT_NOT_VALID_ID_MSG "not a valid identifier"
# define UNSET_NOT_VALID_ID_MSG "not a valid identifier"
# define EXIT_ARG_MSG "numeric argument required"
# define EXIT_TOO_ARG_MSG "too many arguments"
# define CD_TOO_ARG_MSG "too many arguments"
# define IS_DIR_MSG "is a directory"
# define NO_ERROR_MSG "\0"

void	exit_shell(t_sh_context *shx);
t_uint	handle_error(t_uint error_code, t_str err_var);
t_str	get_error_msg(t_uint error_code);
void	set_exit_status(t_uint	error_code);

#endif