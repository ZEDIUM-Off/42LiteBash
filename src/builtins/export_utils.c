// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   export_utils.c                                     :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2023/09/13 15:02:32 by bfaure            #+#    #+#             */
// // /*   Updated: 2023/09/13 15:02:32 by bfaure           ###   ########lyon.fr   */
// // /*                                                                            */
// // /* ************************************************************************** */

// // # include <minish.h>

// // static t_str	create_export_arga(t_cmd **_cmd, t_uint i)
// // {
// // 	t_str			arga;
// // 	t_sh_context	*shx;

// // 	shx = (*_cmd)->shx;
// // 	arga = ft_strdup(shx, (*_cmd)->cmd[i]);
// // 	if (!arga)
// // 		return (NULL);
// // 	if ((*_cmd)->chunk)
// // 	{
// // 		arga = ft_strfjoin(shx, arga, (*_cmd)->chunk->txt[0]);
// // 		if (!arga)
// // 			return (NULL);
// // 	}
// // 	return (arga);
// // }

// // static t_str	create_export_argb(t_cmd **_cmd, t_uint i)
// // {
// // 	t_str			argb;
// // 	t_sh_context	*shx;
// // 	t_uint			n;

// // 	shx = (*_cmd)->shx;
// // 	n = 0;
// // 	if (ft_strchr((*_cmd)->cmd[i], '+'))
// // 		n = 1;
// // 	if (n == 0)
// // 	{
// // 		argb = ft_strdup_char(shx, (*_cmd)->cmd[i], '=');
// // 		if (!argb)
// // 			return (NULL);
// // 	}
// // 	else if (n == 1)
// // 	{
// // 		argb = ft_strdup_char(shx, (*_cmd)->cmd[i], '+');
// // 		if (!argb)
// // 			return (NULL);
// // 	}
// // 	return (argb);
// // }

// // t_str	create_export_argc(t_cmd **_cmd, t_uint i)
// // {
// // 	t_str			argc;
// // 	t_sh_context	*shx;

// // 	shx = (*_cmd)->shx;
// // 	argc = ft_strdup_char(shx, (*_cmd)->cmd[i], '+');
// // 	if (!argc)
// // 		return (NULL);
// // 	argc = ft_strfjoin(shx, argc, "=");
// // 	if (!argc)
// // 		return (NULL);
// // 	if ((*_cmd)->chunk)
// // 	{
// // 		argc = ft_strfjoin(shx, argc, (*_cmd)->chunk->txt[0]);
// // 		if (!argc)
// // 			return (NULL);
// // 	}
// // 	return (argc);
// // }

// static t_uint	check_args_error(t_cmd **_cmd, t_uint i, t_uint index)
// {
// 	t_str	arga;
// 	t_str	argb;
// 	t_str	argc;
// 	t_uint	status;

// 	arga = create_export_arga((_cmd), i);
// 	if (!arga)
// 		return (handle_error(MALLOC_FAIL, NULL));
// 	argb = create_export_argb((_cmd), i);
// 	if (!argb)
// 		return (handle_error(MALLOC_FAIL, NULL));
// 	argc = create_export_argc((_cmd), i);
// 	if (!argc)
// 		return (handle_error(MALLOC_FAIL, NULL));
// 	printf("arga = %s\n", arga);
// 	printf("argb = %s\n", argb);
// 	printf("argc = %s\n", argc);
// 	status = export_cmd_add_to_lst_equal((_cmd), i, index);
// 	if (status != CONTINUE_PROC)
// 		return (handle_error(status, NULL));
// 	return (CONTINUE_PROC);
// }

// // //print lst_get_index pour verifier sa valeur
// // static t_uint	export_cmd_add_to_lst(t_cmd **_cmd, t_uint i, t_uint index)
// // {
// // 	t_str			arga;
// // 	t_str			argb;
// // 	t_str			argc;
// // 	t_sh_context	*shx;
// // 	t_uint			status;

// // 	status = 0;
// // 	shx = (*_cmd)->shx;
// // 	arga = create_export_arga((_cmd), i);
// // 	argb = create_export_argb((_cmd), i);
// // 	argc = create_export_argc((_cmd), i);
// // 	printf("arga = %s\n", arga);
// // 	printf("argb = %s\n", argb);
// // 	printf("argc = %s\n", argc);
// // 	if (!lst_get_index(&shx->envx, argb, ft_strlen_to_char(arga, '=')) && !ft_strchr(arga, '+'))
// // 		status |= lst_add_back(shx, &shx->envx, arga, index);
// // 	else if (!ft_strchr(arga, '+'))
// // 		status |= lst_remplace(shx, &shx->envx, lst_get_index(&shx->envx, argb,
// // 					ft_strlen_to_char(arga, '=')), arga);
// // 	if (!lst_get_index(&shx->envp, argb, ft_strlen_to_char(arga, '=') && !ft_strchr(arga, '+'))
// // 		&& ft_strchr(arga, '='))
// // 		status |= lst_add_back(shx, &shx->envp, arga, index);
// // 	else if (!ft_strchr(arga, '='))
// // 		status |= lst_remplace(shx, &shx->envp, lst_get_index(&shx->envp, argb,
// // 					ft_strlen_to_char(arga, '=')), arga);
// // /*===========================================================================================================*/
// // 	if (lst_get_index(&shx->envx, argb, ft_strlen_to_char(arga, '=')) && ft_strchr(arga, '+'))
// // 		status |= lst_append(shx, &shx->envx, lst_get_index(&shx->envx, argb,
// // 					ft_strlen_to_char(arga, '+')), (*_cmd)->chunk->txt[0]);
// // 	else if (ft_strchr(arga, '+'))
// // 		status |= lst_add_back(shx, &shx->envx, argc, index);
// // 	if (lst_get_index(&shx->envp, argb, ft_strlen_to_char(arga, '=') && ft_strchr(arga, '+')))
// // 		status |= lst_append(shx, &shx->envp, lst_get_index(&shx->envx, argb,
// // 					ft_strlen_to_char(arga, '+')), (*_cmd)->chunk->txt[0]);
// // 	else if (!ft_strchr(arga, '='))
// // 		status |= lst_add_back(shx, &shx->envp, arga, index);
// // 	return (shx->gc->free(shx, argb), status);
// // }

// // t_uint	check_export_return(t_cmd **_cmd, t_uint index, t_uint status)
// // {
// // 	t_uint	i;

// // 	i = 1;
// // 	while ((*_cmd)->chunk && (*_cmd)->cmd[i])
// // 	{
// // 		if (!ft_strchr((*_cmd)->cmd[i], '\"'))
// // 		{
// // 			status |= export_cmd_add_to_lst((_cmd), i, index);
// // 			if (status > 0)
// // 				return (status);
// // 		}
// // 		index++;
// // 		if ((*_cmd)->chunk)
// // 			i = (*_cmd)->chunk->end;
// // 		i++; // TO DO : C'EST LA
// // 		if ((*_cmd)->chunk)
// // 			(*_cmd)->chunk = (*_cmd)->chunk->next;
// // 	}
// // 	return (status);
// // }
