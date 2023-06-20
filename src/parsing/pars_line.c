/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:34 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/20 15:27:23 by  mchenava        ###   ########.fr       */
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
		return (printf("MALLOC FAIL IN SPLIT LINE\n"), -1);
	while ((*line_split)[i])
	{
		printf("g_shx->line_split[%i] = [%s]\n", i, (*line_split)[i]);
		i++;
	}
	log_action();
	return (0);
}

int	find_blocks(t_block	**blocks, t_str *splited)
{
	t_uint	i;
	t_uint	meta;

	i = 0;
	trace("find_blocks", "find blocks", PARSE);
	while (splited[i])
	{
		meta = get_meta_char(&splited[i][0]);
		if (meta == AND || meta == OR)
			add_block(blocks, meta, i);
		i++;
	}
	add_block(blocks, NONE, i);
	return (0);
}

int	pars_line(t_block **out, t_str *splited)
{
	trace("pars_line", "parse the line", PARSE);
	find_blocks(out, splited);
	parse_pipeline(out, splited);
	log_action();
	return (0);
}
