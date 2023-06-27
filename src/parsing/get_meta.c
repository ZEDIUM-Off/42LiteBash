/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:22:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/23 14:26:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	one_char_meta(char *c)
{
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

static t_uint	mult_char_meta(char *c)
{
	if (*c == '<')
	{
		if (*(c + 1) == '<')
			return (HERE_DOC);
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

t_uint	get_meta_char(char *c)
{
	t_uint	type;

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
