/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/20 17:29:19 by bfaure           ###   ########lyon.fr   */
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
	new->cmd = (char **)g_shx->gc->malloc(sizeof(char *) * 10, true);
	if (!new->cmd)
		return (NULL);
	new->chunk = NULL;
	return (new);
}

int	new_cmd(t_cmd **_cmd, t_str *splited)
{
	t_uint	o;
	t_uint	a;
	t_uint	i;

	o = 0;
	a = 0;
	i = 0;
	trace("*new_cmd", "fill cmd struct", PARSE);
	(*_cmd) = create_cmd();
	if (!(*_cmd))
		return (printf("cmd  malloc error\n"), NULL);
	while (splited[i])
	{
		if (i == 0)
		{
			(*_cmd)->cmd = ft_strdup(splited[i]);
			printf("(*_cmd)->cmd = %s\n", (*_cmd)->cmd);
			o++;
		}
		(*_cmd)->chunk = chunk_size(splited);
		i++;
	}
	log_action();
	return (0);
}
