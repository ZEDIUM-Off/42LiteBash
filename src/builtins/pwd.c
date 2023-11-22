/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:14:36 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/22 23:36:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	pwd_builtins(t_sh_context *shx)
{
	t_str	cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		cwd = expand(shx, "PWD", ft_strlen("PWD"));
		if (cwd == NULL || cwd[0] == '\0')
			return (handle_error(PWD_FAIL, "getcwd"));
	}
	printf("%s\n", cwd);
	if (cwd)
		free(cwd);
	return (CONTINUE_PROC);
}
