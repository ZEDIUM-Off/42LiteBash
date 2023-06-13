/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:34 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/13 16:20:06 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	split_line(void)
{
	t_uint	i;

	i = 0;
	trace("split_line", "split the line", PARSE);
	g_shx->line_split = split_parser();
	if (!g_shx->line_split)
		return (printf("MALLOC FAIL IN SPLIT LINE\n"), -1);
	while (g_shx->line_split[i])
	{
		printf("g_shx->line_split[%i] = [%s]\n", i, g_shx->line_split[i]);
		i++;
	}
	log_action();
	return (0);
}

// void	find_blocks()
// {
// 	t_uint	i;
// 	t_uint	meta;

// 	i = 0;
// 	while (g_shx->line_split[i])
// 	{
// 		meta = get_meta_char(&g_shx->line_split[i][0]);
// 		if (meta == IN_REDIRECT
// 			|| meta == OUT_REDIRECT
// 			|| meta == APPEND_REDIRECT
// 			|| meta == HERE_DOC
// 		)

// 	}
	
// }

// int	pars_line(void)
// {
// 	t_uint	i;

// 	i = 0;
// 	find_blocks();

// 	return (0);
// }
