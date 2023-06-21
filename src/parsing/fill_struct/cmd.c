/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/21 15:05:28 by bfaure           ###   ########lyon.fr   */
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

char	*get_valid_paths(char *cmd)
{
	char		*pathname;
	size_t		i;
	t_list		*tmp;

	i = 0;
	if (cmd && access(cmd, X_OK) == 0)
		return (cmd);
	tmp = g_shx->lst_paths;
	while (tmp)
	{
		pathname = ft_strjoin(tmp->data, cmd);
		if (!pathname)
			return (NULL);
		if (access(pathname, X_OK) == 0)
			return (pathname);
		free(pathname);
		tmp = tmp->next;
	}
	return (NULL);
}

int	new_cmd(t_cmd **_cmd, t_str *splited)
{
	t_uint	i;

	i = 0;
	trace("*new_cmd", "fill cmd struct", PARSE);
	(*_cmd) = create_cmd();
	if (!(*_cmd))
		return (printf("cmd  malloc error\n"), MALLOC_FAIL);
	while (splited[i])
	{
		if (i == 0)
		{
			if (check_builtins(splited[0]) == 0)
			{
				(*_cmd)->cmd[i] = get_valid_paths(splited[0]);
				printf("(*_cmd)->cmd in = %s\n", (*_cmd)->cmd[0]);
			}
			else
			{
				(*_cmd)->cmd[i] = ft_strdup(splited[0]);
				printf("(*_cmd)->cmd in = %s\n", (*_cmd)->cmd[0]);
			}
			i = 1;
		}
		if (splited[i] && get_meta_char(splited[i]) != DOUBLE_QUOTE)
		{
			(*_cmd)->cmd[i] = ft_strdup(splited[i]);
			printf("(*_cmd)->cmd out = %s\n", (*_cmd)->cmd[i]);
		}
		//(*_cmd)->chunk = chunk_size(splited);
		i++;
	}
	log_action();
	return (0);
}
