/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:30:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/06 19:05:59 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_read(t_str line_read)
{
	t_p_data	p_data;

	trace("ft_read", "check line", PARSE);
	p_data.pos_cursor = 0;
	printf("p_data.pos_cursor in ft_read at start = %u\n", p_data.pos_cursor);
	while (line_read[p_data.pos_cursor])
	{
		printf("p_data.pos_cursor in ft_read in loop = %u\n", p_data.pos_cursor);
		printf("ft_strlen(line_read) - 1 = %li\n", ft_strlen(line_read) - 1);
		if (line_read[p_data.pos_cursor] == '\"')
		{
			if (double_quote_mode(line_read, &p_data) == DOUBLE_QUOTE_SUCCES)
				printf("DOUBLE_QUOTE_SUCCES\n");
			else
				printf("DOUBLE_QUOTE_ERROR\n");
		}
		p_data.pos_cursor++;
	}
	log_action();
	return (0);
}
