/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/14 11:54:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	find_pipe_start(t_uint	pipe_pos)
{
	t_uint	i;

	i = pipe_pos - 1;
	while (i > 0 && get_meta_char(&g_shx->line_split[i][0]) != PIPE)
		i--;
	return (i);
}

void	parse_pipe(t_pipeline **ppl, t_uint pipe_pos)
{
	t_uint	i;

	i = find_pipe_start(pipe_pos);
	while (i < pipe_pos)
	{
		if (get_meta_char(&g_shx->line_split[i][0]) == 

		
	}
}

void	parse_pipeline(void)
{
	t_uint	i;
	t_block	*block;

	i = 0;
	block = (t_block *)g_shx->block;
	while (g_shx->block)
	{
		while (g_shx->line_split[i] && i < g_shx->block->split_index)
		{
			if (get_meta_char(&g_shx->line_split[i][0]) == PIPE)
			{
				if (!g_shx->block->ppl)
					g_shx->block->ppl = create_ppl(i);
				else
					add_ppl(&g_shx->block->ppl, i);
			}
			i++;
		}
		g_shx->block = g_shx->block->next;
	}
	g_shx->block = block;
}
