/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:58:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/14 19:28:17 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	cd_builtins(t_str path)
{
	t_str	pwd;
	t_uint	size;
	t_str	error;
	t_str	env_name;

	chdir(path);
	size = 1;
	error = NULL;
	while (error == NULL)
	{
		if (size != 1)
			free(pwd);
		pwd = malloc((sizeof(char) * size) + 1);
		error = getcwd(pwd, size);
		size++;
	}
	env_name = malloc(sizeof(char) * 5);
	env_name = ft_strdup("PWD=");
	pwd = ft_strfjoin(env_name, pwd);
	lst_remplace(&g_shx->envp, lst_get_index(&g_shx->envp, "PWD="), pwd);
	if (pwd)
		free(pwd);
	return (1);
}
