/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:34 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/15 17:07:26 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	split_line(t_sh_context *shx, t_str **line_split, t_str line)
{
	if (*line_split)
		free_split_line(shx, line_split);
	*line_split = split_parser(shx, line);
	if (!(*line_split))
		return (MALLOC_FAIL);
	return (CONTINUE_PROC);
}

int	find_blocks(t_sh_context *shx, t_block	**blocks)
{
	t_uint			status;

	status = add_block(shx, blocks);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}

int	pars_line(t_sh_context *shx, t_block **out, t_str *splited)
{
	t_uint			status;

	status = find_blocks(shx, out);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = parse_pipeline(shx, out, splited);
	printf("pars_line status: %d\n", status);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
