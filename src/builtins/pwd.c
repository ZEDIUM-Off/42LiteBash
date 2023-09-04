/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:14:36 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/04 10:44:50 by  mchenava        ###   ########.fr       */
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

t_uint	pwd_builtins(void)
{
	t_str	pwd;

	pwd = get_pwd();
	printf("pwd = %s\n", pwd);
	if (pwd)
		free(pwd);
	return (1);
}
