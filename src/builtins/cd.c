/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:58:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/31 15:39:50 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	cd_builtins(t_str path)
{
	t_str	pwd;
	int		error_code;
	t_str	env_name;

	// trace("cd_builtins", "cd cmd", EXEC);
	error_code = chdir(path);
	printf("cd_builtins error_code : %i\n", error_code);
	if (error_code < 0)
		perror("ERROR : cd");
	pwd = get_pwd();
	env_name = ft_strdup("PWD=");
	if (!env_name)
		return (MALLOC_FAIL);
	pwd = ft_strfjoin(env_name, pwd);
	if (!pwd)
		return (MALLOC_FAIL);
	lst_remplace(&g_shx->envp, lst_get_index(&g_shx->envp, "PWD=", 4), pwd);
	if (pwd)
		free(pwd);
	// log_action();
	return (0);
}
