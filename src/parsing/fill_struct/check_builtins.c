/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:05:06 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/20 15:46:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	check_builtins(char *str)
{
	if (!ft_strncmp(str, "echo", 4) && (str[4] == ' ' || str[4] == '\0'))
		return (ECHO_BI);
	else if (!ft_strncmp(str, "cd", 2) && (str[2] == ' ' || str[2] == '\0'))
		return (CD_BI);
	else if (!ft_strncmp(str, "pwd", 3) && (str[3] == ' ' || str[3] == '\0'))
		return (PWD_BI);
	else if (!ft_strncmp(str, "export", 6)
		&& (str[6] == ' ' || str[6] == '\0'))
		return (EXPORT_BI);
	else if (!ft_strncmp(str, "unset", 5) && (str[5] == ' ' || str[5] == '\0'))
		return (UNSET_BI);
	else if (!ft_strncmp(str, "env", 3) && (str[3] == ' ' || str[3] == '\0'))
		return (ENV_BI);
	else if (!ft_strncmp(str, "exit", 4) && (str[4] == ' ' || str[4] == '\0'))
		return (EXIT_BI);
	return (CONTINUE_PROC);
}
