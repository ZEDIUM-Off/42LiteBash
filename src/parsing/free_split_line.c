/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:29:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/14 10:35:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	free_split_line(void)
{
	t_uint	i;

	i = 0;
	while (g_shx->line_split[i])
	{
		g_shx->gc->free(g_shx->line_split[i]);
		i++;
	}
	g_shx->gc->free(g_shx->line_split);
	g_shx->line_split = NULL;
}
