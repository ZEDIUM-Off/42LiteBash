/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:29:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:52:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	free_split_line(t_sh_context *shx, t_str **line_split)
{
	t_uint	i;

	i = 0;
	while ((*line_split)[i])
	{
		shx->gc->free(shx, (*line_split)[i]);
		i++;
	}
	shx->gc->free(shx, *line_split);
	*line_split = NULL;
}
