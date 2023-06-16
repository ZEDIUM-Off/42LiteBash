/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/16 16:47:22 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

//new_cmd(i, pipe_pos);

t_cmd	*create_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)g_shx->gc->malloc(sizeof(t_cmd), true);
	if (!new)
		return (NULL);
	new->cmd = NULL;
	new->opt = NULL;
	new->opt = (char **)g_shx->gc->malloc(sizeof(char *), true);
	if (!new->opt)
		return (NULL);
	new->arg = NULL;
	new->chunk = NULL;
	return (new);
}

t_cmd	*new_cmd(t_uint p_start, t_uint p_end)
{
	t_uint	n;
	t_uint	o;

	n = 0;
	o = 0;
	trace("*new_cmd", "fill cmd struct", PARSE);
	g_shx->blocks->ppl->cmd = create_cmd();
	if (!g_shx->blocks->ppl->cmd)
		return (printf("g_shx->blocks->ppl->cmd  malloc error\n"), NULL);
	while (g_shx->line_split[p_start] && p_start != p_end)
	{
		printf("g_shx->line_split[p_start] = %s\n", g_shx->line_split[p_start]);
		if (n == 0)
		{
			if (g_shx->line_split[p_start][0] == PIPE)
				p_start++;
			printf("g_shx->line_split[p_start] in if 1 = %s\n", g_shx->line_split[p_start]);
			if (g_shx && g_shx->blocks && g_shx->blocks->ppl && g_shx->blocks->ppl->cmd)
				g_shx->blocks->ppl->cmd->cmd = g_shx->line_split[p_start];
			//printf("cmd->cmd = %s\n", g_shx->blocks->ppl->cmd->cmd);
			n++;
		}
		if (g_shx->line_split[p_start][0] == '-')
		{
			g_shx->blocks->ppl->cmd->opt[o] = g_shx->line_split[p_start];
			printf("cmd->opt[%i] = %s\n", o, g_shx->blocks->ppl->cmd->opt[o]);
			o++;
		}
		p_start++;
	}
	log_action();
	return (NULL);
}
