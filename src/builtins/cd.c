/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:58:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/21 16:10:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	update_pwd(t_sh_context *shx, t_str new, t_str old)
{
	t_uint	status;

	status = lst_set(&shx->env, env_get_index(&shx->env, "PWD"),
			ft_strjoin(shx, "PWD=", new));
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	status = lst_set(&shx->env, env_get_index(&shx->env, "OLDPWD"),
			ft_strjoin(shx, "OLDPWD=", old));
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	return (CONTINUE_PROC);
}

t_uint	cd_builtins(t_sh_context *shx, t_str path)
{
	t_uint	status;
	t_str	tmp;
	t_str	oldpwd;

	tmp = NULL;
	oldpwd = NULL;
	if (!path)
		tmp = ft_strdup(shx, shx->home);
	else if (ft_strcmp(path, "-") == 0)
		tmp = expand(shx, "OLDPWD", ft_strlen("OLDPWD"));
	else
		tmp = ft_strdup(shx, path);
	if (!tmp)
		return (handle_error(MALLOC_FAIL, NULL));
	// oldpwd = expand(shx, "PWD", ft_strlen("PWD"));
	oldpwd = get_pwd(shx);
	if (chdir(tmp) == -1)
		return (handle_error(CD_FAIL, tmp));
	status = update_pwd(shx, get_pwd(shx), oldpwd);
	shx->gc->free(shx, tmp);
	shx->gc->free(shx, oldpwd);
	return (status);
}
