/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:29:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/20 15:22:11 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	free_split_line(t_str **line_split)
{
	t_uint	i;

	i = 0;
	while ((*line_split)[i])
	{
		g_shx->gc->free((*line_split)[i]);
		i++;
	}
	g_shx->gc->free(*line_split);
	*line_split = NULL;
}
