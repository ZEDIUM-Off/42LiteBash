/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:30:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/08 10:48:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_read(t_str line_read)
{
	t_p_data	p_data;

	trace("ft_read", "check line", PARSE);
	p_data.pos_cursor = 0;
	check_double_quote_mode(line_read, &p_data);
	log_action();
	return (0);
}

int	check_double_quote_mode(t_str line_read, t_p_data *p_data)
{
	trace("check_double_quote_mode", "check line for double quote", PARSE);
	while (line_read[p_data->pos_cursor])
	{
		if (line_read[p_data->pos_cursor] == '\"')
		{
			if (double_quote_mode(line_read, p_data) == DOUBLE_QUOTE_SUCCES)
			{
				printf("DOUBLE_QUOTE_SUCCES\n");
				break ;
			}
			else
			{
				printf("DOUBLE_QUOTE_ERROR\n");
				break ;
			}
		}
		p_data->pos_cursor++;
	}
	// log_action();
	return (0);
}

int	check_simple_quote_mode(t_str line_read, t_p_data *p_data)
{
	trace("check_simple_quote_mode", "check line for simple quote", PARSE);
	while (line_read[p_data->pos_cursor])
	{
		if (line_read[p_data->pos_cursor] == '\'')
		{
			if (simple_quote_mode(line_read, p_data) == SIMPLE_QUOTE_SUCCES)
			{
				printf("SIMPLE_QUOTE_SUCCES\n");
				break ;
			}
			else
			{
				printf("SIMPLE_QUOTE_ERROR\n");
				break ;
			}
		}
		p_data->pos_cursor++;
	}
	//log_action();
	return (0);
}
