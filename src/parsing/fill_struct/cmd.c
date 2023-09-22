/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/21 11:27:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	create_cmd(t_sh_context *shx, t_cmd **new, t_uint size)
{
	*new = (t_cmd *)shx->gc->malloc(shx, sizeof(t_cmd), true);
	if (!(*new))
		return (handle_error(MALLOC_FAIL, NULL));
	(*new)->cmd = (char **)shx->gc->malloc(shx,
			sizeof(char *) * (size + 1), true);
	if (!(*new)->cmd)
		return (handle_error(MALLOC_FAIL, NULL));
	(*new)->chunk = NULL;
	(*new)->shx = shx;
	return (CONTINUE_PROC);
}

t_uint	get_valid_paths(t_sh_context *shx, t_str *cmd, t_str src)
{
	t_list		*tmp;

	if (src && access(src, X_OK) == 0)
	{
		*cmd = ft_strdup(shx, src);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	tmp = shx->lst_paths;
	while (tmp)
	{
		*cmd = ft_strjoin(shx, tmp->data, src);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
		if (access(*cmd, X_OK) == 0)
			return (CONTINUE_PROC);
		shx->gc->free(shx, *cmd);
		tmp = tmp->next;
	}
	return (handle_error(CMD_NOT_FOUND, src));
}

t_uint	handle_quote(t_sh_context *shx, t_str *cmd, t_str *splited, t_uint *i)
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
		return (handle_error(SYNTAX_ERROR, "quote"));
	if (check_builtins(splited[*i]))
	{
		*cmd = ft_strdup(shx, splited[*i]);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	else
	{
		status = get_valid_paths(shx, cmd, splited[*i]);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (*i == 1)
		*i += 1;
	return (CONTINUE_PROC);
}

t_uint	fill_cmd(t_sh_context *shx, t_cmd **_cmd, t_str *splited)
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
			status = handle_quote(
					shx, &((*_cmd)->cmd[cmd_curs++]), splited, &i);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
		else if (splited[i])
		{
			(*_cmd)->cmd[cmd_curs++] = ft_strdup(shx, splited[i]);
			if (!(*_cmd)->cmd[cmd_curs - 1])
				return (handle_error(MALLOC_FAIL, NULL));
		}
		i++;
	}
	(*_cmd)->cmd[cmd_curs] = NULL;
	return (CONTINUE_PROC);
}

t_uint	new_cmd(t_sh_context *shx, t_cmd **_cmd, t_str *splited)
{
	t_uint	i;
	t_uint	status;

	i = 0;
	while (splited[i])
		i++;
	status = create_cmd(shx, _cmd, i);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = fill_cmd(shx, _cmd, splited);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = get_chunks(shx, &(*_cmd)->chunk, (*_cmd)->cmd);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = cmd_expand(shx, _cmd);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
