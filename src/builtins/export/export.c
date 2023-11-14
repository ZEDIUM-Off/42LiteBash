/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:55:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/14 11:42:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	export(t_sh_context *shx, t_export *to_export)
{
	t_uint	status;
	int		index;
	t_str	tmp;

	tmp = NULL;
	index = env_get_index(&shx->env, to_export->name);
	status = CONTINUE_PROC;
	if (to_export->type == PLUS_EQUAL && index != -1)
		tmp = lst_get(&shx->env, index);
	status = build_var(shx, to_export, tmp);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	if (index == -1)
	{
		if (to_export->type == NONE)
			lst_add_back(shx, &shx->env, ft_strdup(shx, to_export->name));
		else
			lst_add_back(shx, &shx->env, ft_strdup(shx, to_export->builded));
	}
	else if (to_export->type != NONE)
		lst_set(&shx->env, index, ft_strdup(shx, to_export->builded));
	return (status);
}
