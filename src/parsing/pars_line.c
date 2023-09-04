/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:34 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/04 11:02:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	split_line(t_sh_context *shx, t_str **line_split, t_str line)
{
	t_uint	i;

	i = 0;
	if (*line_split)
		free_split_line(shx, line_split);
	*line_split = split_parser(shx, line);
	if (!(*line_split))
		return (printf("MALLOC FAIL IN SPLIT LINE\n"), MALLOC_FAIL);
	while ((*line_split)[i])
	{
		printf("g_shx->line_split[%i] = [%s]\n", i, (*line_split)[i]);
		i++;
	}
	return (0);
}

int	find_blocks(t_sh_context *shx, t_block	**blocks, t_str *splited)
{
	t_uint			i;
	t_uint			status;
	bool			par;
	t_uint			meta;

	i = 0;
	par = false;
	while (splited[i])
	{
		meta = get_meta_char(&splited[i++][0]);
		if (meta == O_PARENTHESIS)
			par = true;
		else if (meta == C_PARENTHESIS)
			par = false;
		if ((meta == AND || meta == OR) && par == false)
		{
			status = add_block(shx, blocks, meta, i - 1);
			if (status != 0)
				return (status);
		}
	}
	status = add_block(shx, blocks, NONE, i);
	if (status != 0)
		return (status);
	return (0);
}

int	pars_line(t_sh_context *shx, t_block **out, t_str *splited)
{
	t_uint			status;

	status = find_blocks(shx, out, splited);
	if (status != 0)
		return (status);
	status = parse_pipeline(shx, out, splited);
	if (status != 0)
		return (status);
	return (0);
}
