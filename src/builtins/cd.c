/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:58:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/24 10:45:31 by bfaure           ###   ########lyon.fr   */
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

t_uint	cd_get_path(t_sh_context *shx, t_str path, t_str *tmp)
{
	*tmp = NULL;
	if (!path || ft_strcmp(path, "~") == 0)
		*tmp = ft_strdup(shx, shx->home);
	else if (ft_strcmp(path, "-") == 0)
		*tmp = expand(shx, "OLDPWD", ft_strlen("OLDPWD"));
	else
		*tmp = ft_strdup(shx, path);
	if (!*tmp)
		return (handle_error(MALLOC_FAIL, NULL));
	return (CONTINUE_PROC);
}

t_uint	cd_builtins(t_sh_context *shx, t_str path)
{
	t_uint	status;
	t_str	tmp;
	t_str	oldpwd;
	t_str	pwd;

	oldpwd = NULL;
	pwd = NULL;
	status = cd_get_path(shx, path, &tmp);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (handle_error(MALLOC_FAIL, NULL));
	if (chdir(tmp) == -1)
		return (free(oldpwd), handle_error(CD_FAIL, tmp));
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (free(oldpwd), handle_error(MALLOC_FAIL, NULL));
	status = update_pwd(shx, pwd, oldpwd);
	if (status != CONTINUE_PROC)
		return (free(pwd), free(oldpwd), handle_error(status, NULL));
	shx->gc->free(shx, tmp);
	free(oldpwd);
	free(pwd);
	return (status);
}
