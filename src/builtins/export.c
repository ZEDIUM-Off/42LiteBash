/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/31 16:28:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

// static t_str	make_arg_var(t_cmd **_cmd, t_uint i)
// {
	
// }

static t_uint	export_cmd_add__to_lst(t_cmd **_cmd, t_uint i, t_uint index)
{
	t_str			argv;
	t_str			argb;
	t_sh_context	*shx;

	shx = (*_cmd)->shx;
	argv = ft_strdup((*_cmd)->cmd[i]);
	argb = ft_strdup_char((*_cmd)->cmd[i], '=');
	if (!argb || !argv)
		return (MALLOC_FAIL);
	if ((*_cmd)->chunk)
	{
		argv = ft_strfjoin(argv, (*_cmd)->chunk->txt[0]);
		if (!argv)
			return (MALLOC_FAIL);
	}
	if (!lst_get_index(&shx->envx, argb, ft_strlen_to_char(argv, '=')))
		lst_add_back(shx, &shx->envx, argv, index);
	else
		lst_remplace(shx, &shx->envx, lst_get_index(&shx->envx, argb,
				ft_strlen_to_char(argv, '=')), argv);
	if (!lst_get_index(&shx->envp, argb, ft_strlen_to_char(argv, '='))
		&& ft_strchr(argv, '=') != NULL)
		lst_add_back(shx, &shx->envp, argv, index);
	else if (ft_strchr(argv, '=') != NULL)
		lst_remplace(shx, &shx->envp, lst_get_index(&shx->envp, argb,
				ft_strlen_to_char(argv, '=')), argv);
	return (free(argb), 0);
}

t_uint	export_cmd(t_cmd **_cmd)
{
	t_uint			i;
	t_uint			index;
	t_sh_context	*shx;

	shx = (*_cmd)->shx;
	trace(shx, "export_cmd", "cmd export", EXEC);
	index = lst_get_last(&shx->envp)->index + 1;
	i = 1;
	if (!(*_cmd)->cmd[1])
		lst_print(&shx->envx, "declare -x %u %s\n");
	else
	{
		while ((*_cmd)->chunk || (*_cmd)->cmd[i])
		{
			if (export_cmd_add__to_lst((_cmd), i, index) == MALLOC_FAIL)
				return (MALLOC_FAIL);
			index++;
			if ((*_cmd)->chunk)
				i = (*_cmd)->chunk->end;
			i++;
			if ((*_cmd)->chunk)
				(*_cmd)->chunk = (*_cmd)->chunk->next;
		}
	}
	sort_env_export(shx);
	log_action(shx);
	return (0);
}
