#ifndef ENUMS_H
# define ENUMS_H

#include <minish.h>

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

#endif