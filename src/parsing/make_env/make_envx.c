/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:59:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/30 14:59:33 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	make_envx(t_sh_context *shx, t_uint env_var_name)
{
	t_str	env_name;
	t_uint	status;

	if (env_var_name == PWD)
	{
		env_name = ft_strdup(shx, "PWD=");
		if (!env_name)
			return (handle_error(MALLOC_FAIL, NULL));
		env_name = ft_strfjoin(shx, env_name, get_pwd());
		if (!env_name)
			return (handle_error(MALLOC_FAIL, NULL));
		status = lst_add_back(shx, &shx->envx, env_name);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (env_var_name == SHLVL)
	{
		status = lst_add_back(shx, &shx->envx, "SHLVL=2");
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (env_var_name == OLD_PWD)
	{
		status = lst_add_back(shx, &shx->envx, "OLD_PWD=");
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (env_var_name == ALL)
	{
		env_name = ft_strdup(shx, "PWD=");
		if (!env_name)
			return (handle_error(MALLOC_FAIL, NULL));
		env_name = ft_strfjoin(shx, env_name, get_pwd());
		if (!env_name)
			return (handle_error(MALLOC_FAIL, NULL));
		status = lst_add_back(shx, &shx->envx, env_name);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = lst_add_back(shx, &shx->envx, "SHLVL=2");
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = lst_add_back(shx, &shx->envx, "OLDPWD=");
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

static t_uint	check_status_env(t_sh_context *shx, t_status_env *data)
{
	t_uint	status;

	if (data->pwd < 1)
	{
		status = make_envx(shx, PWD);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (data->old_pwd < 1)
	{
		status = make_envx(shx, OLD_PWD);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	if (data->shlvl < 1)
	{
		status = make_envx(shx, SHLVL);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}

static t_uint	cmp_env(t_sh_context *shx, t_status_env *data, t_list *tmp)
{
	t_uint	status;

	if (ft_strnstr(tmp->data, "PWD=", 4))
		data->pwd++;
	else if (ft_strnstr(tmp->data, "SHLVL=", 6))
	{
		status = lst_remplace(shx, &shx->envx, lst_get_index(&tmp, tmp->data),
				inc_shlvl(shx, tmp->data));
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		data->shlvl++;
	}
	else if (ft_strnstr(tmp->data, "OLDPWD=", 8))
		data->old_pwd++;
	return (CONTINUE_PROC);
}

t_uint	check_envx(t_sh_context *shx)
{
	t_list			*tmp;
	t_status_env	*data;
	t_uint			status;

	status = 0;
	if (!shx->envp)
	{
		status = make_envx(shx, ALL);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	else
	{
		data = shx->s_env;
		tmp = shx->envx;
		while (tmp)
		{
			status = cmp_env(shx, data, tmp);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			tmp = tmp->next;
		}
		status = check_status_env(shx, data);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}
