/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:14:36 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/14 10:57:27 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	get_pwd(t_sh_context *shx)
{
	t_str	pwd;
	t_uint	size;
	t_str	error;

	size = 1;
	error = NULL;
	while (error == NULL)
	{
		if (size != 1)
			gc_free(shx, pwd);
		pwd = gc_malloc(shx, sizeof(char) * size + 1, true);
		error = getcwd(pwd, size);
		size++;
	}
	return (pwd);
}

t_uint	pwd_builtins(t_sh_context *shx)
{
	t_str	pwd;

	pwd = get_pwd(shx);
	printf("%s\n", pwd);
	if (pwd)
		gc_free(shx, pwd);
	return (CONTINUE_PROC);
}
