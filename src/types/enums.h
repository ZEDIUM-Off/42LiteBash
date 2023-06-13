/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/13 13:15:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# include <minish.h>

enum e_meta_type
{
	NONE,
	IN_REDIRECT, // <
	OUT_REDIRECT, // >
	APPEND_REDIRECT, // >>
	HERE_DOC, // <<
	PIPE, // |
	SINGLE_QUOTE, // '
	DOUBLE_QUOTE, // "
	DOLLAR, //$
	DOLLAR_Q, // $?
	DOLLAR_D, // $$
	OR, // ||
	AND, // &&
	O_PARENTHESIS, // (
	C_PARENTHESIS, // )
	WILD_CARD, // *
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
	GARB_ALLOC_ERROR,
	TRACKER_ALLOC_ERROR,
};

enum e_user_error_codes
{
	SYNTAX_ERROR,
	SYNTAX_OK,
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
