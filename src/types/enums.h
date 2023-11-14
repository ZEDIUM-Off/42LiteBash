/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/09 17:28:17 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

// # include <minish.h>

enum e_meta_type
{
	NONE,
	IN_REDIRECT,
	OUT_REDIRECT,
	APPEND_REDIRECT,
	HERE_DOC,
	DOLLAR_Q,
	DOLLAR_D,
	PLUS_EQUAL,
	PIPE,
	DOLLAR,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	EQUAL,
	MINUS,
	PLUS,
};

extern t_str	g_meta_char[];

enum e_env_var_name
{
	PWD = 1,
	SHLVL = 2,
	OLD_PWD = 3,
	ALL = 4,
};

enum e_builtin_type
{
	ECHO_BI = 1,
	CD_BI,
	PWD_BI,
	EXPORT_BI,
	UNSET_BI,
	ENV_BI,
	EXIT_BI,
};

enum e_step_type
{
	START,
	INIT_TRACK,
	PARSE,
	EXEC,
	END,
};

enum e_error_codes
{
	CONTINUE_PROC = 0,
	STOP_PROC = 1,
	EXIT_SHELL = 2,
	MALLOC_FAIL,
	PIPE_FAIL,
	FORK_FAIL,
	WAITPID_FAIL,
	NULL_DATA,
	DUP_FAIL,
	UNCLOSED_QUOTES,
	SYNTAX_ERROR,
	NO_FILE_DIR,
	NO_PERM,
	CMD_NOT_FOUND,
	IS_DIR,
	OPEN_FAIL,
	CLOSE_FAIL,
	KILL_FAIL,
	CD_FAIL,
	EXPORT_NOT_VALID_ID,
	EXIT_ARG,
	EXIT_TOO_ARG,
	SKIP_FORK,
	INVALID_META,
};

#endif
