/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/20 16:50:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_cmd	*create_cmd(void)
{
	t_cmd	*new;

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
	t_chunk	*chunk;

	n = 0;
	o = 0;
	a = 0;
	trace("*new_cmd", "fill cmd struct", PARSE);
	cmd = create_cmd();
	if (!cmd)
		return (printf("cmd  malloc error\n"), NULL);
	while (p_start != p_end)
	{
		if (n == 0)
		{
			while (get_meta_char(&g_shx->line_split[p_start][0]) == PIPE)
				p_start++;
			if (cmd)
			{
				cmd->cmd = ft_strdup(g_shx->line_split[p_start]);
				cmd->opt[o] = ft_strdup(cmd->cmd);
				printf("cmd->cmd = %s\n", cmd->cmd);
				o++;
			}
			n++;
		}
		if (g_shx->line_split[p_start][0] == '-')
		{
			cmd->opt[o] = ft_strdup(g_shx->line_split[p_start]);
			o++;
		}
		else if (g_shx->line_split[p_start] != cmd->cmd)
		{
			cmd->arg[a] = ft_strdup(g_shx->line_split[p_start]);
			printf("cmd->arg[%i] = %s\n", a, cmd->arg[a]);
			a++;
		}
		chunk = chunk_size(g_shx->line_split);
		p_start++;
	}
	log_action();
	return (cmd);
}
