/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:59:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/30 14:59:33 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	check_status_env(t_sh_context *shx, t_status_env *data)
{
	t_uint	status;

	status = 0;
	if (data->pwd < 1)
	{
		status = make_var_pwd(shx);
		if (status != CONTINUE_PROC)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	if (data->old_pwd < 1)
	{
		status = make_var_oldpwd(shx);
		if (status != CONTINUE_PROC)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	if (data->shlvl < 1)
	{
		status = make_var_shlvl(shx);
		if (status != CONTINUE_PROC)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	return (CONTINUE_PROC);
}

static t_uint	cmp_env(t_status_env *data, t_list *tmp)
{
	t_uint	status;

	status = 0;
	if (ft_strnstr(tmp->data, "PWD=", 4))
		data->pwd++;
	else if (ft_strnstr(tmp->data, "SHLVL=", 6))
		data->shlvl++;
	else if (ft_strnstr(tmp->data, "OLDPWD=", 8))
		data->old_pwd++;
	return (CONTINUE_PROC);
}

t_uint	check_env(t_sh_context *shx)
{
	t_list			*tmp;
	t_status_env	*data;
	t_uint			status;

	status = 0;
	if (!shx->env)
	{
		status = make_var_all(shx);
		if (status != CONTINUE_PROC)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	else
	{
		data = shx->s_env;
		tmp = shx->env;
		while (tmp)
		{
			status = cmp_env(data, tmp);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			tmp = tmp->next;
		}
		check_status_env(shx, data);
	}
	return (CONTINUE_PROC);
}
