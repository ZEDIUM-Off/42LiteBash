/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:05:06 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/24 13:32:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	check_builtins(char *str)
{
	printf("check_builtins str = %s\n", str);
	if (!ft_strncmp(str, "echo", 4))
		return (ECHO_BI);
	else if (!ft_strncmp(str, "cd", 2))
		return (CD_BI);
	else if (!ft_strncmp(str, "pwd", 3))
		return (PWD_BI);
	else if (!ft_strncmp(str, "export", 6))
		return (EXPORT_BI);
	else if (!ft_strncmp(str, "unset", 5))
		return (UNSET_BI);
	else if (!ft_strncmp(str, "env", 3))
		return (ENV_BI);
	else if (!ft_strncmp(str, "exit", 4))
		return (EXIT_BI);
	printf("check_builtins = NONE\n");
	return (0);
}
