/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:34 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/27 10:48:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	split_line(t_str **line_split, t_str line)
{
	t_uint	i;

	i = 0;
	trace("split_line", "split the line", PARSE);
	if (*line_split)
		free_split_line(line_split);
	*line_split = split_parser(line);
	if (!(*line_split))
		return (printf("MALLOC FAIL IN SPLIT LINE\n"), MALLOC_FAIL);
	while ((*line_split)[i])
	{
		printf("g_shx->line_split[%i] = [%s]\n", i, (*line_split)[i]);
		i++;
	}
	log_action();
	return (0);
}

int	find_meta_and_add_block(
	t_block **blocks, t_str *splited, t_uint i, bool *par)
{
	t_uint	meta;
	t_uint	status;

	meta = get_meta_char(&splited[i][0]);
	if (meta == O_PARENTHESIS)
		*par = true;
	else if (meta == C_PARENTHESIS)
		*par = false;
	if ((meta == AND || meta == OR) && *par == false)
	{
		status = add_block(blocks, meta, i);
		if (status != 0)
			return (status);
	}
	return (0);
}

int	find_blocks(t_block	**blocks, t_str *splited)
{
	t_uint	i;
	t_uint	status;
	bool	par;

	i = 0;
	par = false;
	trace("find_blocks", "find blocks", PARSE);
	while (splited[i])
	{
		status = find_meta_and_add_block(blocks, splited, i, &par);
		if (status != 0)
			return (status);
		i++;
	}
	status = add_block(blocks, NONE, i);
	if (status != 0)
		return (status);
	return (0);
}

int	pars_line(t_block **out, t_str *splited)
{
	t_uint	status;

	trace("pars_line", "parse the line", PARSE);
	status = find_blocks(out, splited);
	if (status != 0)
		return (status);
	status = parse_pipeline(out, splited);
	if (status != 0)
		return (status);
	log_action();
	return (0);
}
