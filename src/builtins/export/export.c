/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:55:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/07 17:40:57 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_str	export_find_name(t_cmd **_cmd)
{
	static t_uint	i = 1;
	t_sh_context	*shx;

	shx = (*_cmd)->shx;
	while ((*_cmd)->cmd[i])
	{
		printf("i in export_find_name = %u\n", i);
		if (!(*_cmd)->cmd[i + 1])
			return ((*_cmd)->cmd[i]);
		if ((*_cmd)->cmd[i + 1][0] == '\0' && ((*_cmd)->cmd[i + 2][0] == '=' || (*_cmd)->cmd[i + 2][0] == '+'))
			return (i += 2, ft_strjoin(shx, (*_cmd)->cmd[i - 2], (*_cmd)->cmd[i]));
		if ((*_cmd)->cmd[i + 1][0] != '\0')
			return ((*_cmd)->cmd[i]);
		i++;
	}
	return (NULL);
}

static t_str	join_export(t_sh_context *shx, t_cmd **_cmd)
{
	t_str	arga;
	t_uint	i;

	i = 1;
	arga = ft_strdup(shx, "");
	while ((*_cmd)->cmd[i])
	{
		printf("PASS\n");
		printf("i = %u\n", i);
		printf("i + 1 = %u\n", i + 1);
		if ((*_cmd)->chunk && ((*_cmd)->cmd[i + 1] && (*_cmd)->cmd[i + 1][0] == '\0'))
		{
			printf("chunk = %s\n", (*_cmd)->chunk->txt[0]);
			arga = ft_strfjoin(shx, arga, (*_cmd)->chunk->txt[0]);
			i = (*_cmd)->chunk->end;
			printf("i = %u\n", i);
			(*_cmd)->chunk = (*_cmd)->chunk->next;
		}
		if ((*_cmd)->cmd[i] && ((*_cmd)->cmd[i + 1] && (*_cmd)->cmd[i + 1][0] == '\0'))
		{
			i += 2;
			printf("cmd[%u] = %s\n", i, (*_cmd)->cmd[i]);
			arga = ft_strfjoin(shx, arga, (*_cmd)->cmd[i]);
		}
		i++;
	}
	return (arga);
}

static t_uint	export_add(t_sh_context *shx, t_cmd **_cmd, t_uint status)
{
	int		export_check;
	t_str	argv1;
	t_str	argv2;
	t_str	argv3;

	argv1 = export_find_name(_cmd);
	if (ft_strchr(argv1, '+'))
		argv1 = ft_strfjoin(shx, argv1, "=");
	argv2 = join_export(shx, _cmd);
	export_check = lst_check(&shx->envx, argv1);
	status = lst_get_index(&shx->envx, argv2);
	printf("argv1 = %s\n", argv1);
	printf("argv2 = %s\n", argv2);
	printf("export_check = %d\n", export_check);
	printf("status = %d\n", status);
	// argv1 = ft_strjoin(shx, argv1, "=");
	argv3 = ft_strfjoin(shx, argv1, argv2);
	// printf("argv1  2 = %s\n", argv1);
	printf("argv2  2 = %s\n", argv2);
	if (export_check == -1)
	{
		status = lst_add_back(shx, &shx->envx, argv3);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (ft_strchr(argv2, '+'))
		{
			status = lst_append(shx, &shx->envx, status, argv2);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
		if (ft_strchr(argv2, '='))
		{
			status = lst_add_back(shx, &shx->envp, argv3);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
	}
	else
	{
		status = lst_set(&shx->envx, status, argv3);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		if (ft_strchr(argv2, '+'))
		{
			status = lst_append(shx, &shx->envx, status, argv2);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
		if (ft_strchr(argv2, '='))
		{
			status = lst_add_back(shx, &shx->envp, argv3);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
	}
	return (CONTINUE_PROC);
}

t_uint	export_cmd(t_cmd **_cmd)
{
	t_sh_context	*shx;
	t_uint			status;

	shx = (*_cmd)->shx;
	status = SKIP_FORK;
	if (!(*_cmd)->cmd[1])
		return (lst_print(&shx->envx, "declare -x %s\n"));
	else
	{
		status = export_add(shx, _cmd, status);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}
