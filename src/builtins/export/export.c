/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:55:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/04 10:12:29 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

// t_uint	export(t_sh_context *shx, t_export *to_export)
// {
// 	t_uint	status;
// 	int		index_envx;
// 	int		index_envp;
// 	t_str	tmp;

// 	tmp = NULL;
// 	index_envx = env_get_index(shx, &shx->envx, to_export->name);
// 	index_envp = env_get_index(shx, &shx->envp, to_export->name);
// 	status = CONTINUE_PROC;
// 	if (to_export->type == PLUS_EQUAL && index_envx != -1)
// 		tmp = lst_get(&shx->envx, index_envx);
// 	status = build_var(shx, to_export, tmp);
// 	if (status != CONTINUE_PROC)
// 		return (handle_error(status, NULL));
// 	if (index_envp == -1 && index_envx == -1)
// 	{
// 		if (to_export->type == NONE)
// 			lst_add_back(shx, &shx->envx, ft_strdup(shx, to_export->name));
// 		else
// 			lst_add_back(shx, &shx->envx, ft_strdup(shx, to_export->builded));
// 		if (to_export->type == EQUAL)
// 			lst_add_back(shx, &shx->envp, ft_strdup(shx, to_export->builded));
// 	}
// 	else if (to_export->type != NONE)
// 	{
// 		lst_set(&shx->envx, index_envx, ft_strdup(shx, to_export->builded));
// 		lst_set(&shx->envp, index_envp, ft_strdup(shx, to_export->builded));
// 	}
// 	sort_env_export(shx);
// 	return (status);
// }

t_uint	process_plus_equal(t_sh_context *shx, t_export *to_export, t_str *tmp, int index_envx)
{
	if (to_export->type == PLUS_EQUAL && index_envx != -1)
		*tmp = lst_get(&shx->envx, index_envx);
	return (build_var(shx, to_export, *tmp));
}

void	handle_new_var(t_sh_context *shx, t_export *to_export, int index_envp, int index_envx)
{
	if (index_envp == -1 && index_envx == -1)
	{
		if (to_export->type == NONE)
			lst_add_back(shx, &shx->envx, ft_strdup(shx, to_export->name));
		else
			lst_add_back(shx, &shx->envx, ft_strdup(shx, to_export->builded));
		if (to_export->type == EQUAL)
			lst_add_back(shx, &shx->envp, ft_strdup(shx, to_export->builded));
	}
}

void	update_existing_var(t_sh_context *shx, t_export *to_export, int index_envx, int index_envp)
{
	if (to_export->type != NONE)
	{
		lst_set(&shx->envx, index_envx, ft_strdup(shx, to_export->builded));
		lst_set(&shx->envp, index_envp, ft_strdup(shx, to_export->builded));
	}
}

t_uint	export(t_sh_context *shx, t_export *to_export)
{
	t_uint	status;
	int		index_envx;
	int		index_envp;
	t_str	tmp;

	tmp = NULL;
	index_envx = env_get_index(shx, &shx->envx, to_export->name);
	index_envp = env_get_index(shx, &shx->envp, to_export->name);
	status = process_plus_equal(shx, to_export, &tmp, index_envx);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	handle_new_var(shx, to_export, index_envp, index_envx);
	update_existing_var(shx, to_export, index_envx, index_envp);
	sort_env_export(shx);
	return (status);
}

