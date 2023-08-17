/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:58:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/15 13:09:30 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	cd_builtins(t_str path)
{
	t_str	pwd;
	int		error_code;
	t_str	env_name;

	trace("cd_builtins", "cd cmd", EXEC);
	error_code = chdir(path);
	printf("cd_builtins error_code : %i\n", error_code);
	if (error_code < 0)
		perror("ERROR : cd");
	pwd = get_pwd();
	env_name = malloc(sizeof(char) * 5);
	env_name = ft_strdup("PWD=");
	pwd = ft_strfjoin(env_name, pwd);
	lst_remplace(&g_shx->envp, lst_get_index(&g_shx->envp, "PWD="), pwd);
	if (pwd)
		free(pwd);
	log_action();
	return (1);
}
