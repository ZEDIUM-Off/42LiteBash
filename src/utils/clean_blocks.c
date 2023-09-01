/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:17:13 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 17:03:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	clean_chunk(t_sh_context *shx, t_chunk **chunk)
{
	t_chunk			*tmp;

	while (*chunk)
	{
		tmp = *chunk;
		*chunk = (*chunk)->next;
		if (tmp->under_chunk)
			clean_chunk(shx, &tmp->under_chunk);
		if (tmp->blocks)
			clean_blocks(shx, &tmp->blocks);
		free_split_line(shx, &tmp->txt);
		shx->gc->free(shx, tmp);
	}
}

void	clean_cmd(t_sh_context *shx, t_cmd **cmd)
{
	t_cmd			*tmp;

	tmp = *cmd;
	clean_chunk(shx, &tmp->chunk);
	free_split_line(shx, &tmp->cmd);
	shx->gc->free(shx, tmp);
}

void	clean_ppl(t_sh_context *shx, t_pipeline **ppl)
{
	t_pipeline		*tmp;

	while (*ppl)
	{
		tmp = *ppl;
		*ppl = (*ppl)->next;
		clean_cmd(shx, &tmp->cmd);
		if (tmp->redir.infile.file_name)
			shx->gc->free(shx, tmp->redir.infile.file_name);
		if (tmp->redir.outfile.file_name)
			shx->gc->free(shx, tmp->redir.outfile.file_name);
		shx->gc->free(shx, tmp);
	}
}

void	clean_blocks(t_sh_context *shx, t_block **blocks)
{
	t_block			*tmp;

	while (*blocks)
	{
		tmp = *blocks;
		*blocks = (*blocks)->next;
		clean_ppl(shx, &tmp->ppl);
		shx->gc->free(shx, tmp);
	}
}
