/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/24 12:26:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_cmd(t_cmd **new, t_uint size)
{
	printf ("cmd size: %d\n", size);
	*new = (t_cmd *)g_shx->gc->malloc(sizeof(t_cmd), true);
	if (!(*new))
		return (MALLOC_FAIL);
	(*new)->cmd = (char **)g_shx->gc->malloc(sizeof(char *) * (size + 1), true);
	if (!(*new)->cmd)
		return (MALLOC_FAIL);
	(*new)->chunk = NULL;
	return (0);
}

t_uint	get_valid_paths(t_str	*cmd, t_str src)
{
	t_list		*tmp;

	if (src && access(src, X_OK) == 0)
		*cmd = ft_strdup(src);
	tmp = g_shx->lst_paths;
	while (tmp)
	{
		*cmd = ft_strjoin(tmp->data, src);
		if (!*cmd)
			return (MALLOC_FAIL);
		if (access(*cmd, X_OK) == 0)
			return (0);
		free(*cmd);
		tmp = tmp->next;
	}
	return (CMD_NOT_FOUND);
}

t_uint	new_cmd(t_cmd **_cmd, t_str *splited)
{
	t_uint	i;
	t_uint	meta;
	t_uint	status;
	t_uint	cmd_curs;

	i = 0;
	trace("*new_cmd", "fill cmd struct", PARSE);
	while (splited[i])
		i++;
	status = create_cmd(_cmd, i);
	if (status !=	0)
		return (status);
	i = 0;
	cmd_curs = 0;
	while (splited[i])
	{
		meta = get_meta_char(&splited[i][0]);
		if (i == 0)
		{
			if (meta != NONE)
				return (printf("ERROR: meta char at the beginning of the line\n"), SYNTAX_ERROR);
			if (check_builtins(splited[0]))
				(*_cmd)->cmd[cmd_curs++] = ft_strdup(splited[0]);
			else
			{
				status = get_valid_paths(&(*_cmd)->cmd[cmd_curs++], splited[0]);
				if (status != 0)
					return (printf("error cmd = %d on [%s]\n", status, splited[0]), status);
			}
		}
		else if (splited[i])
			(*_cmd)->cmd[cmd_curs++] = ft_strdup(splited[i]);
		i++;
	}
	(*_cmd)->cmd[cmd_curs] = NULL;
	status = get_chunks(&(*_cmd)->chunk, splited);
	if (status != 0)
		return (status);
	log_action();
	return (0);
}
