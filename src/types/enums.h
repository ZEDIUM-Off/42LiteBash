/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/06 13:26:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# include <minish.h>

enum e_quoting
{
	IN_REDIRECT, // <
	OUT_REDIRECT, // >
	APPEND_REDIRECT, // >>
	IN_TO_DELIM, // <<
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

enum e_error_codes
{
	GARB_ALLOC_ERROR,
	TRACKER_ALLOC_ERROR,
};

#endif
