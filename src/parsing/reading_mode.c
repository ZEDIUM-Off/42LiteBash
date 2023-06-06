/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:30:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/06 19:04:46 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	double_quote_mode(t_str line_read, t_p_data *p_data)
{
	t_uint	b;

	trace("double_quote_mode", "check double quote", PARSE);
	b = 1;
	p_data->pos_cursor += 1;
	printf("p_data->pos_cursor in double_quote_mode at start = %u\n", p_data->pos_cursor);
	printf("PASS IN DOUBLE_QUOTE_MODE\n");
	while (line_read[p_data->pos_cursor] && b != 2)
	{
		printf("b = %u\n", b);
		printf("p_data->pos_cursor in double_quote_mode in loop = %u\n", p_data->pos_cursor);
		if (line_read[p_data->pos_cursor] == '\"')
			b++;
		p_data->pos_cursor++;
	}
	log_action();
	if (b <= 1)
		return (DOUBLE_QUOTE_ERROR);
	return (DOUBLE_QUOTE_SUCCES);
}

int	bracket_mode(void)
{
	return (BRACKET_SUCCES);
}
