/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/14 14:37:13 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

//new_cmd(i, pipe_pos);

t_cmd	*new_cmd(t_uint p_start, t_uint p_end)
{
	t_uint	n;
	t_uint	o;
	// t_cmd	*d_cmd;

	n = 0;
	o = 0;
	while (g_shx->line_split[p_start] && p_start != p_end)
	{
		printf("g_shx->line_split[p_start] = %s\n", g_shx->line_split[p_start]);
		if (n == 0)
		{
			if (g_shx->line_split[p_start][0] != PIPE)
				p_start++;
			g_shx->blocks->ppl->cmd->cmd = g_shx->line_split[p_start];
			printf("cmd->cmd = %s\n", g_shx->blocks->ppl->cmd->cmd);
		}
		if (g_shx->line_split[p_start][0] == '-')
		{
			g_shx->blocks->ppl->cmd->opt[o] = g_shx->line_split[p_start];
			printf("cmd->opt[%i] = %s\n", o, g_shx->blocks->ppl->cmd->opt[o]);
			o++;
		}
		p_start++;
	}
	return (NULL);
}