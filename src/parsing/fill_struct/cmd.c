/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/28 12:31:35 by  mchenava        ###   ########.fr       */
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

t_uint	handle_quote(t_str *cmd, t_str *splited, t_uint *i)
{
	t_uint	meta;
	t_uint	status;

	meta = get_meta_char(&splited[*i][0]);
	if (meta == SINGLE_QUOTE || meta == DOUBLE_QUOTE)
	{
		*i += 1;
		while (get_meta_char(&splited[*i][0]) != meta)
			*i += 1;
	}
	if (*i == 2)
		*i = 1;
	else if (*i != 0)
		return (printf("error quote = %d on [%s]\n", *i, splited[*i]), SYNTAX_ERROR);
	if (check_builtins(splited[*i]))
		*cmd = ft_strdup(splited[*i]);
	else
	{
		status = get_valid_paths(cmd, splited[*i]);
		if (status != 0)
			return (printf("error cmd = %d on [%s]\n", status, splited[*i]), status);
	}
	if (*i == 1)
		*i += 1;
	return (0);
}

t_uint	fill_cmd(t_cmd **_cmd, t_str *splited)
{
	t_uint	cmd_curs;
	t_uint	status;
	t_uint	i;

	cmd_curs = 0;
	i = 0;
	while (splited[i])
	{
		if (cmd_curs == 0)
		{
			status = handle_quote(&((*_cmd)->cmd[cmd_curs++]), splited, &i);
			if (status != 0)
				return (status);
		}
		else if (splited[i])
		{
			(*_cmd)->cmd[cmd_curs++] = ft_strdup(splited[i]);
			if (!(*_cmd)->cmd[cmd_curs - 1])
				return (MALLOC_FAIL);
		}
		i++;
	}
	(*_cmd)->cmd[cmd_curs] = NULL;
	
	return (0);
}

t_uint	new_cmd(t_cmd **_cmd, t_str *splited)
{
	t_uint	i;
	t_uint	status;

	i = 0;
	trace("*new_cmd", "fill cmd struct", PARSE);
	while (splited[i])
		i++;
	status = create_cmd(_cmd, i);
	if (status != 0)
		return (status);
	status = fill_cmd(_cmd, splited);
	if (status != 0)
		return (status);
	i = 0;
	while ((*_cmd)->cmd[i++])
		printf("cmd[%d] = [%s]\n", i, (*_cmd)->cmd[i]);
	status = get_chunks(&(*_cmd)->chunk, (*_cmd)->cmd);
	if (status != 0)
		return (status);
	log_action();
	return (0);
}


