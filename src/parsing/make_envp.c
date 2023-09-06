/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:20:00 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/06 21:26:10 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

static t_uint	make_env(t_sh_context *shx, t_uint env_var_name)
{
	t_str	env_name;
	t_uint	status;

	status = 0;
	if (env_var_name == PWD)
	{
		env_name = ft_strdup("PWD=");
		env_name = ft_strfjoin(env_name, get_pwd());
		status += lst_add_back(shx, &shx->envp, env_name, 0);
	}
	if (env_var_name == SHLVL)
		lst_add_back(shx, &shx->envp, "SHLVL=1", 1);
	if (env_var_name == OLD_PWD)
		lst_add_back(shx, &shx->envp, "OLD_PWD=", 2);
	if (env_var_name == ALL)
	{
		env_name = ft_strdup("PWD=");
		env_name = ft_strfjoin(env_name, get_pwd());
		status += lst_add_back(shx, &shx->envp, env_name, 0);
		status += lst_add_back(shx, &shx->envp, "SHLVL=2", 1);
		status += lst_add_back(shx, &shx->envp, "OLDPWD=", 2);
	}
	return (status);
}

static t_uint	check_status_env(t_sh_context *shx, t_status_env *data)
{
	t_uint	status;

	status = 0;
	if (data->pwd < 1)
		status += make_env(shx, PWD);
	if (data->old_pwd < 1)
		status += make_env(shx, OLD_PWD);
	if (data->shlvl < 1)
		status += make_env(shx, SHLVL);
	return (status);
}

static t_uint	cmp_env(t_sh_context *shx, t_status_env *data, t_list *tmp)
{
	t_uint	status;

	status = 0;
	if (ft_strnstr(tmp->data, "PWD=", 4))
		data->pwd++;
	else if (ft_strnstr(tmp->data, "SHLVL=", 6))
	{
		status += lst_remplace(shx, &shx->envp, tmp->index,
				inc_shlvl(tmp->data));
		data->shlvl++;
	}
	else if (ft_strnstr(tmp->data, "OLDPWD=", 8))
		data->old_pwd++;
	return (status);
}

t_uint	check_env(t_sh_context *shx)
{
	t_list			*tmp;
	t_status_env	*data;
	t_uint			status;

	status = 0;
	if (!shx->envp)
		status += make_env(shx, ALL);
	else
	{
		data = shx->s_env;
		tmp = shx->envp;
		while (tmp)
		{
			status += cmp_env(shx, data, tmp);
			tmp = tmp->next;
		}
		check_status_env(shx, data);
	}
	return (status);
}


