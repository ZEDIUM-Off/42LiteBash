/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:38:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/20 11:16:40 by  mchenava        ###   ########.fr       */
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
	(*new)->shx = shx;
	return (CONTINUE_PROC);
}

t_uint	extract_cmd(t_sh_context *shx, t_str *cmd, t_str *splited, t_uint *i)
{
	t_uint	status;
	t_str	tmp;

	tmp = NULL;
	status = extract_quotes(shx, splited[*i], &tmp);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (check_builtins(tmp))
	{
		*cmd = ft_strdup(shx, tmp);
		if (!*cmd)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	else
	{
		status = get_valid_paths(shx, cmd, tmp);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	*i += 1;
	return (CONTINUE_PROC);
}

t_uint	fill_cmd(t_sh_context *shx, t_cmd **_cmd, t_str *splited, t_uint size)
{
	t_uint	cmd_curs;
	t_uint	i;

	cmd_curs = 0;
	i = 0;
	while (splited[i] && i < size)
	{
		if (splited[i] && splited[i][0])
		{
			(*_cmd)->cmd[cmd_curs++] = ft_strdup(shx, splited[i]);
			if (!(*_cmd)->cmd[cmd_curs - 1])
				return (handle_error(MALLOC_FAIL, NULL));
		}
		i++;
	}
	(*_cmd)->cmd[cmd_curs] = NULL;
	(*_cmd)->size = cmd_curs;
	return (CONTINUE_PROC);
}

t_uint	get_cmd_path(t_sh_context *shx, t_cmd **_cmd)
{
	t_uint	i;
	t_uint	meta;

	i = 0;
	while ((*_cmd)->cmd[i])
	{
		meta = get_meta_char(&(*_cmd)->cmd[i][0]);
		if (meta >= IN_REDIRECT && meta <= HERE_DOC)
		{
			i += 2;
			continue ;
		}
		if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i][0])
			return (extract_cmd(shx, &(*_cmd)->cmd[i], (*_cmd)->cmd, &i));
		i++;
	}
	return (CONTINUE_PROC);
}

t_uint	new_cmd(t_sh_context *shx, t_cmd **_cmd, t_str *splited, t_uint size)
{
	t_uint	status;

	status = create_cmd(shx, _cmd, size);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = fill_cmd(shx, _cmd, splited, size);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = get_cmd_path(shx, _cmd);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}
