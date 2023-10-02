/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:22:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/02 15:50:33 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	one_char_meta(char *c)
{
	if (c == NULL)
		return (NONE);
	if (*c == '\'')
		return (SINGLE_QUOTE);
	else if (*c == '"')
		return (DOUBLE_QUOTE);
	else if (*c == '=')
		return (EQUAL);
	else if (*c == ';' || *c == '&' || *c == '(' || *c == ')')
		return (INVALID_META);
	return (NONE);
}

static t_uint	mult_char_meta(char *c)
{
	if (c == NULL)
		return (NONE);
	if (*c == '+')
	{
		if (*(c + 1) == '=')
			return (PLUS_EQUAL);
		return (INVALID_META);
	}
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
		return (PIPE);
	return (NONE);
}

t_uint	get_meta_char(char *c)
{
	t_uint	type;

	if (c == NULL)
		return (NONE);
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
