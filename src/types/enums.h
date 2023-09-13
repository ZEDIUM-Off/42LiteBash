/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/08 15:57:30 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

// # include <minish.h>

enum e_meta_type
{
	NONE,
	IN_REDIRECT, // <
	OUT_REDIRECT, // >
	APPEND_REDIRECT, // >>
	HERE_DOC, // <<
	DOLLAR_Q, // $?
	DOLLAR_D, // $$
	// OR, // ||
	// AND, // &&
	PIPE, // |
	DOLLAR, //$
	SINGLE_QUOTE, // '
	DOUBLE_QUOTE, // "
	// O_PARENTHESIS, // (
	// C_PARENTHESIS, // )
	// PARENTHESIS, // ()
	// WILD_CARD, // *
};

extern t_str g_meta_char[];

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
	CD_BI = 2,
	PWD_BI = 3,
	EXPORT_BI = 4,
	UNSET_BI = 5,
	ENV_BI = 6,
	EXIT_BI = 7,
};

enum e_step_type
{
	START,
	INIT_TRACK,
	PARSE,
	EXEC,
	END,
};

enum e_internal_error_codes
{
	GARB_ALLOC_ERROR = 1,
	TRACKER_ALLOC_ERROR = 2,
	MALLOC_FAIL = 3,
	PIPE_FAIL = 4,
	FORK_FAIL = 5,
	EXECVE_FAIL = 6,
	WAITPID_FAIL = 7,
	PROC_NOT_TERMINATED = 8,
	NULL_DATA = 9,
};

enum e_user_error_codes
{
	SYNTAX_ERROR,
	NO_FILE_DIR,
	IMPLICIT_REDIRECT,
	SYNTAX_OK,
	CMD_NOT_FOUND,
};

enum e_parsing_error
{
	DOUBLE_QUOTE_ERROR = -1,
	SIMPLE_QUOTE_ERROR = -2,
	BRACKET_ERROR = -3,
};

enum e_parsing_succes
{
	DOUBLE_QUOTE_SUCCES = 1,
	SIMPLE_QUOTE_SUCCES = 2,
	BRACKET_SUCCES = 3,
};

enum e_chunk_type
{
	DOUBLE_QUOTE_CHUNK,
	SIMPLE_QUOTE_CHUNK,
	BRACKET_CHUNK,
};

#endif
