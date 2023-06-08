/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:22:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/08 13:03:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static int	one_char_meta(char *c)
{
	trace("one_char_meta", "checking", PARSE);
	if (*c == '\'')
		return (SINGLE_QUOTE);
	else if (*c == '"')
		return (DOUBLE_QUOTE);
	else if (*c == '(')
		return (O_PARENTHESIS);
	else if (*c == ')')
		return (C_PARENTHESIS);
	else if (*c == '*')
		return (WILD_CARD);
	else if (*c == '&' && *(c + 1) == '&')
		return (AND);
	return (NONE);
}

static int	mult_char_meta(char *c)
{
	trace("mult_char_meta", "checking", PARSE);
	if (*c == '<')
	{
		if (*(c + 1) == '<')
			return (IN_TO_DELIM);
		return (IN_REDIRECT);
	}
	else if (*c == '>')
	{
		if (*(c + 1) == '>')
			return (APPEND_REDIRECT);
		return (OUT_REDIRECT);
	}
	else if (*c == '|')
	{
		if (*(c + 1) == '|')
			return (OR);
		return (PIPE);
	}
	return (NONE);
}

int	get_meta_char(char *c)
{
	int	type;

	trace("get_meta_char", "checking", PARSE);
	type = one_char_meta(c);
	if (type != NONE)
		return (type);
	type = mult_char_meta(c);
	if (type != NONE)
		return (type);
	else if (*c == '$')
	{
		if (*(c + 1) == '?')
			return (DOLLAR_Q);
		else if (*(c + 1) == '$')
			return (DOLLAR_D);
		return (DOLLAR);
	}
	return (NONE);
}
