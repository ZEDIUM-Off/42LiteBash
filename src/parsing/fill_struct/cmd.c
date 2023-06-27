/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/23 01:40:33 by  mchenava        ###   ########.fr       */
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

char	*get_valid_paths(char *cmd)
{
	char		*pathname;
	t_list		*tmp;

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
		if (i == 0)
		{
			meta = get_meta_char(&splited[i][0]);
			if (check_builtins(splited[0]) == 0
				&& !(meta >= SINGLE_QUOTE && meta <= C_PARENTHESIS))
			{
				(*_cmd)->cmd[cmd_curs++] = get_valid_paths(splited[0]);
				printf("(*_cmd)->cmd in = %s\n", (*_cmd)->cmd[0]);
			}
			else if (!(meta >= SINGLE_QUOTE && meta <= C_PARENTHESIS))
			{
				(*_cmd)->cmd[cmd_curs++] = ft_strdup(splited[0]);
				printf("(*_cmd)->cmd in = %s\n", (*_cmd)->cmd[0]);
			}
			i = 1;
		}
		if (splited[i] && get_meta_char(splited[i]) != DOUBLE_QUOTE)
		{
			(*_cmd)->cmd[cmd_curs++] = ft_strdup(splited[i]);
			// printf("(*_cmd)->cmd[%d] out = %s\n",i, (*_cmd)->cmd[i]);
		}
		i++;
	}
	printf("i = %d\n", i);
	(*_cmd)->cmd[cmd_curs] = NULL;
	i = 0;
	while ((*_cmd)->cmd[i])
	{
		printf("(*_cmd)->cmd = %s\n", (*_cmd)->cmd[i]);
		i++;
	}
	status = chunk_size(&(*_cmd)->chunk, splited);
	if (status != 0)
		return (status);
	log_action();
	return (0);
}
