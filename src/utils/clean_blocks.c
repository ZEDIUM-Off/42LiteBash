/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:17:13 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/13 15:30:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	clean_cmd(t_sh_context *shx, t_cmd **cmd)
{
	t_cmd			*tmp;

	tmp = *cmd;
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
