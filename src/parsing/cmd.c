/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/19 23:38:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

//new_cmd(i, pipe_pos);

t_cmd	*create_cmd(void)
{
	t_cmd	*new;

	printf("g_shx->blocks->ppl in create_cmd %p\n", g_shx->blocks->ppl);
	new = (t_cmd *)g_shx->gc->malloc(sizeof(t_cmd), true);
	if (!new)
		return (NULL);
	new->cmd = NULL;
	new->opt = NULL;
	new->opt = (char **)g_shx->gc->malloc(sizeof(char *) * 5, true);
	if (!new->opt)
		return (NULL);
	new->arg = NULL;
	new->arg = (char **)g_shx->gc->malloc(sizeof(char *) * 5, true);
	if (!new->arg)
		return (printf("AHHHHHHHHHHHHHHHHHH\n"), NULL);
	new->chunk = NULL;
	return (new);
}

t_cmd	*new_cmd(t_uint p_start, t_uint p_end)
{
	t_uint	n;
	t_uint	o;
	t_uint	a;
	t_cmd	*cmd;

	n = 0;
	o = 0;
	a = 0;
	trace("*new_cmd", "fill cmd struct", PARSE);
	cmd = create_cmd();
	if (!cmd)
		return (printf("cmd  malloc error\n"), NULL);
	printf("p_end = %i\n", p_end);
	while (p_start != p_end)
	{
		printf("out B %i\n", p_start);
		printf("g_shx->line_split[p_start] = %s\n", g_shx->line_split[p_start]);
		if (n == 0)
		{
			printf("in B %i\n", p_start);
			while (g_shx->line_split[p_start][0] == '|')
				p_start++;
			printf("g_shx->line_split[p_start] in if 1 = %c\n", g_shx->line_split[p_start][0]);
			printf("in A %i\n", p_start);
			if (cmd)
				cmd->cmd = g_shx->line_split[p_start];
			printf("cmd->cmd = %s\n", cmd->cmd);
			n++;
		}
		else if (g_shx->line_split[p_start][0] == '|' && g_shx->line_split[p_start][1] == '|')
		{
			printf("|| foud\n");
			break ;
		}
		if (g_shx->line_split[p_start][0] == '-')
		{
			cmd->opt[o] = g_shx->line_split[p_start];
			printf("cmd->opt[%i] = %s\n", o, cmd->opt[o]);
			o++;
		}
		else if (g_shx->line_split[p_start] != cmd->cmd)
		{
			printf("g_shx->line_split[%i] = %s\n", p_start, g_shx->line_split[p_start]);
			cmd->arg[a] = g_shx->line_split[p_start];
			printf("cmd->arg[%i] = %s\n", a, cmd->arg[a]);
			a++;
		}
		p_start++;
	}
	printf("OUT\n");
	log_action();
	return (cmd);
}
