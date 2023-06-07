/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:30:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/07 18:12:37 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	double_quote_mode(t_str line_read, t_p_data *p_data)
{
	t_uint	b;

	trace("double_quote_mode", "check double quote", PARSE);
	b = 1;
	p_data->pos_cursor += 1;
	while (line_read[p_data->pos_cursor] && b != 2)
	{
		if (line_read[p_data->pos_cursor] == '\"')
			b++;
		p_data->pos_cursor++;
	}
	//log_action();
	if (b <= 1)
		return (DOUBLE_QUOTE_ERROR);
	return (DOUBLE_QUOTE_SUCCES);
}

int	bracket_mode(void)
{
	return (BRACKET_SUCCES);
}

int	simple_quote_mode(t_str line_read, t_p_data *p_data)
{
	t_uint	b;

	trace("simple_quote_mode", "check simple quote", PARSE);
	b = 1;
	p_data->pos_cursor += 1;
	while (line_read[p_data->pos_cursor] && b != 2)
	{
		if (line_read[p_data->pos_cursor] == '\'')
			b++;
		p_data->pos_cursor++;
	}
	//log_action();
	if (b <= 1)
		return (DOUBLE_QUOTE_ERROR);
	return (DOUBLE_QUOTE_SUCCES);
}
