/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:19:35 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/23 17:32:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	make_var_pwd(t_sh_context *shx)
{
	t_uint	status;
	t_str	env_name;

	status = 0;
	env_name = ft_strdup(shx, "PWD=");
	if (!env_name)
		return (handle_error(MALLOC_FAIL, NULL));
	env_name = ft_strfjoin(shx, env_name, getcwd(NULL, 0));
	if (!env_name)
		return (handle_error(MALLOC_FAIL, NULL));
	status = lst_add_back(shx, &shx->env, env_name);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	return (CONTINUE_PROC);
}

t_uint	make_var_shlvl(t_sh_context *shx)
{
	t_uint	status;

	status = 0;
	status = lst_add_back(shx, &shx->env, "SHLVL=2");
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	return (CONTINUE_PROC);
}

t_uint	make_var_oldpwd(t_sh_context *shx)
{
	t_uint	status;

	status = 0;
	status = lst_add_back(shx, &shx->env, "OLD_PWD=");
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	return (CONTINUE_PROC);
}

t_uint	make_var_all(t_sh_context *shx)
{
	t_uint	status;

	status = 0;
	status = make_var_pwd(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	status = make_var_shlvl(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	status = make_var_oldpwd(shx);
	if (status != CONTINUE_PROC)
		return (handle_error(MALLOC_FAIL, NULL));
	return (CONTINUE_PROC);
}
