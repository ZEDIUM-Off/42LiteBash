/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/14 02:11:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_str	create_export_argv(t_cmd **_cmd, t_uint i)
{
	t_str			argv;
	t_sh_context	*shx;

	shx = (*_cmd)->shx;
	argv = ft_strdup(shx, (*_cmd)->cmd[i]);
	if (!argv)
		return (NULL);
	if ((*_cmd)->chunk)
	{
		argv = ft_strfjoin(shx, argv, (*_cmd)->chunk->txt[0]);
		if (!argv)
			return (NULL);
	}
	return (argv);
}

static t_str	create_export_argb(t_cmd **_cmd, t_uint i)
{
	t_str			argb;
	t_sh_context	*shx;

	shx = (*_cmd)->shx;
	argb = ft_strdup_char(shx, (*_cmd)->cmd[i], '=');
	if (!argb)
		return (NULL);
	return (argb);
}

static t_uint	export_cmd_add_to_lst(t_cmd **_cmd, t_uint i, t_uint index)
{
	t_str			argv;
	t_str			argb;
	t_sh_context	*shx;
	t_uint			status;

	status = 0;
	shx = (*_cmd)->shx;
	argv = create_export_argv((_cmd), i);
	if (!argv)
		return (handle_error(MALLOC_FAIL, NULL));
	argb = create_export_argb((_cmd), i);
	if (!argb)
		return (handle_error(MALLOC_FAIL, NULL));
	if (!lst_get_index(&shx->envx, argb, ft_strlen_to_char(argv, '=')))
		status = lst_add_back(shx, &shx->envx, argv, index);
	else
		status = lst_remplace(shx, &shx->envx, lst_get_index(&shx->envx, argb,
					ft_strlen_to_char(argv, '=')), argv);
	if (status != CONTINUE_PROC)
		return (
			shx->gc->free(shx, argb), shx->gc->free(shx, argv),
			handle_error(status, NULL));
	if (!lst_get_index(&shx->envp, argb, ft_strlen_to_char(argv, '='))
		&& ft_strchr(argv, '=') != NULL)
		status = lst_add_back(shx, &shx->envp, argv, index);
	else if (ft_strchr(argv, '=') != NULL)
		status = lst_remplace(shx, &shx->envp, lst_get_index(&shx->envp, argb,
					ft_strlen_to_char(argv, '=')), argv);
	if (status != CONTINUE_PROC)
		return (
			shx->gc->free(shx, argb), shx->gc->free(shx, argv),
			handle_error(status, NULL));
	return (shx->gc->free(shx, argb), CONTINUE_PROC);
}

static t_uint	check_export_return(t_cmd **_cmd, t_uint index)
{
	t_uint			i;
	t_uint			status;

	i = 1;
	while ((*_cmd)->chunk || (*_cmd)->cmd[i])
	{
		status = export_cmd_add_to_lst((_cmd), i, index);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		index++;
		if ((*_cmd)->chunk)
			i = (*_cmd)->chunk->end;
		i++;
		if ((*_cmd)->chunk)
			(*_cmd)->chunk = (*_cmd)->chunk->next;
	}
	return (CONTINUE_PROC);
}

t_uint	export_cmd(t_cmd **_cmd)
{
	t_uint			index;
	t_sh_context	*shx;
	t_uint			status;

	shx = (*_cmd)->shx;
	index = lst_get_last(&shx->envp)->index + 1;
	if (!(*_cmd)->cmd[1])
		status = lst_print(&shx->envx, "declare -x %u %s\n");
	else
		status = check_export_return((_cmd), index);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (sort_env_export(shx), status);
}
