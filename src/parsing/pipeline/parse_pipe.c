/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/14 13:54:07 by  mchenava        ###   ########.fr       */
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
	t_uint	meta;

	i = find_pipe_start(pipe_pos);
	(*ppl)->cmd = new_cmd(i, pipe_pos);
	while (i < pipe_pos)
	{
		meta = get_meta_char(&g_shx->line_split[i][0]);
		if (meta == APPEND_REDIRECT)
			(*ppl)->redir = {.out_type = APPEND_REDIRECT,
				.outfile = new_file(g_shx->line_split[i + 1])};
		if (meta == OUT_REDIRECT)
			(*ppl)->redir = {.out_type = OUT_REDIRECT,
				.outfile = new_file(g_shx->line_split[i + 1])};
		if (meta == HERE_DOC)
			(*ppl)->redir = {.in_type = HERE_DOC,
				.in_file = NULL};
		if (meta == IN_REDIRECT)
			(*ppl)->redir = {.in_type = IN_REDIRECT,
				.in_file = new_file(g_shx->line_split[i + 1])};
		i++;
	}
}

void	parse_pipeline(void)
{
	t_uint	i;
	t_block	*block;

	i = 0;
	block = (t_block *)g_shx->blocks;
	while (g_shx->blocks)
	{
		while (g_shx->line_split[i] && i < g_shx->blocks->split_index)
		{
			if (get_meta_char(&g_shx->line_split[i][0]) == PIPE)
			{
				if (!g_shx->blocks->ppl)
					g_shx->blocks->ppl = create_ppl(i);
				else
					add_ppl(&g_shx->blocks->ppl, i);
			}
			i++;
		}
		g_shx->blocks = g_shx->blocks->next;
	}
	g_shx->blocks = block;
}
