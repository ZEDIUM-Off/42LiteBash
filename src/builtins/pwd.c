/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:14:36 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/31 16:21:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	get_pwd(void)
{
	t_str	pwd;
	t_uint	size;
	t_str	error;

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
	return (pwd);
}

t_uint	pwd_builtins(t_sh_context *shx)
{
	t_str	pwd;

	trace(shx, "pwd_builtins", "pwd cmd", EXEC);
	pwd = get_pwd();
	printf("pwd = %s\n", pwd);
	if (pwd)
		free(pwd);
	log_action(shx);
	return (1);
}
