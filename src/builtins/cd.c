/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:58:44 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/20 10:26:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	cd_builtins(t_sh_context *shx, t_str path)
{
	t_str	pwd;
	int		error_code;
	t_str	env_name;

	error_code = chdir(path);
	printf("cd_builtins error_code : %i\n", error_code);
	if (error_code < 0)
		perror("ERROR : cd");
	pwd = get_pwd();
	env_name = ft_strdup(shx, "PWD=");
	if (!env_name)
		return (handle_error(MALLOC_FAIL, NULL));
	pwd = ft_strfjoin(shx, env_name, pwd);
	if (!pwd)
		return (handle_error(MALLOC_FAIL, NULL));
	lst_remplace(shx,
		&shx->envp, lst_get_index(&shx->envp, "PWD="), pwd);
	if (pwd)
		free(pwd);
	return (CONTINUE_PROC);
}
