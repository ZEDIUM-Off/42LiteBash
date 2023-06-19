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
	t_uint	a;
	t_cmd	*cmd;

	n = 0;
	o = 0;
	a = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	while (g_shx->line_split[p_start] && p_start != p_end)
	{
		printf("g_shx->line_split[p_start] = %s\n", g_shx->line_split[p_start]);
		if (n == 0)
		{
			if (g_shx->line_split[p_start] != PIPE)
				p_start++;
			cmd->cmd = g_shx->line_split[p_start];
			printf("cmd->cmd = %s\n", cmd->cmd);
			n++;
		}
		else if (g_shx->line_split[p_start][0] == "-")
		{
			cmd->opt[o] = g_shx->line_split[p_start];
			printf("cmd->opt[%li] = %s\n", o, cmd->opt[o]);
			o++;
		}
		else
		{
			cmd->arg[a] = g_shx->line_split[p_start];
			printf("cmd-arg[%li] = %s\n", a, cmd->arg[a]);
			a++;
		}
		p_start++;
	}
	return (cmd);
}
