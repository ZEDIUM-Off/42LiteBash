/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:34 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/20 11:35:37 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	split_line(void)
{
	t_uint	i;

	i = 0;
	trace("split_line", "split the line", PARSE);
	if (g_shx->line_split)
		free_split_line();
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

void	find_blocks(void)
{
	t_uint	i;
	t_uint	meta;
	t_uint  block_ctr = 0;

	i = 0;
	trace("find_blocks", "find blocks", PARSE);
	while (g_shx->line_split[i])
	{
		meta = get_meta_char(&g_shx->line_split[i][0]);
		if (meta == AND || meta == OR)
		{
			block_ctr++;
			if (g_shx->blocks == NULL)
				g_shx->blocks = create_block(meta, i);
			else
				add_block(&g_shx->blocks, meta, i);
		}
		i++;
	}
	if (g_shx->blocks == NULL)
		g_shx->blocks = create_block(NONE, i);
	else
		add_block(&g_shx->blocks, meta, i);
	printf("nb block = %d", block_ctr);
}

int	pars_line(void)
{
	trace("pars_line", "parse the line", PARSE);
	find_blocks();
	parse_pipeline();
	log_action();
	return (0);
}
