/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:17:13 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/26 15:42:11 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void clean_chunk(t_chunk **chunk)
{
	t_chunk *tmp;

	while (*chunk)
	{
		tmp = *chunk;
		*chunk = (*chunk)->next;
		if (tmp->under_chunk)
			clean_chunk(&tmp->under_chunk);
		if (tmp->blocks)
			clean_blocks(&tmp->blocks);
		free_split_line(&tmp->txt);
		g_shx->gc->free(tmp);
	}
}

void	clean_cmd(t_cmd **cmd)
{
	t_cmd *tmp;

	tmp = *cmd;
	clean_chunk(&tmp->chunk);
	free_split_line(&tmp->cmd);
	g_shx->gc->free(tmp);
}

void	clean_ppl(t_pipeline **ppl)
{
	t_pipeline *tmp;

	while (*ppl)
	{
		tmp = *ppl;
		*ppl = (*ppl)->next;
		clean_cmd(&tmp->cmd);
		if (tmp->redir.infile.file_name)
			g_shx->gc->free(tmp->redir.infile.file_name);
		if (tmp->redir.outfile.file_name)
			g_shx->gc->free(tmp->redir.outfile.file_name);
		g_shx->gc->free(tmp);
	}
}

void	clean_blocks(t_block **blocks)
{
	t_block *tmp;

	while (*blocks)
	{
		tmp = *blocks;
		*blocks = (*blocks)->next;
		clean_ppl(&tmp->ppl);
		g_shx->gc->free(tmp);
	}
}
