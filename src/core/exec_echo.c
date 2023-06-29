/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:37:37 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/28 15:37:37 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	exec_echo(t_cmd **_cmd)
{
	bool	n;
	t_uint	i;

	n = 0;
	i = 0;
	while ((*_cmd)->cmd[i])
	{
		if (check_builtins((*_cmd)->cmd[0]) == ECHO_BI)
		{
			if (ft_strncmp((*_cmd)->cmd[1], "-n",
					ft_strlen((*_cmd)->cmd[1])) == 0)
				n = 1;
			echo_builtins((*_cmd)->cmd[i + 1], 1 + n);
		}
		i++;
	}
	// i = 0;
	// while ((*_cmd)->chunk)
	// {
	// 	while ((*_cmd)->chunk->txt[i])
	// 	{
	// 		if (check_builtins((*_cmd)->cmd[0]) == ECHO_BI)
	// 		{
	// 			if (ft_strncmp((*_cmd)->cmd[1], "-n",
	// 					ft_strlen((*_cmd)->cmd[1])) == 0)
	// 				n = 1;
	// 			echo_builtins((*_cmd)->chunk->txt[i], 0);
	// 		}
	// 		i++;
	// 	}
	// 	(*_cmd)->chunk = (*_cmd)->chunk->next;
	// }
	if (n == 0)
		printf("\n");	
	return (0);
}
