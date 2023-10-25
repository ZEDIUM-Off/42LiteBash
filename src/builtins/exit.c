/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:09:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/24 12:23:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	exit_bi(t_cmd *cmd)
{
	t_uint	i;

	i = 0;
	printf ("exit\n");
	while (cmd->cmd[1] && cmd->cmd[1][i])
	{
		if (!ft_isdigit(cmd->cmd[1][i]))
			return (handle_error(EXIT_ARG, cmd->cmd[1]));
		i++;
	}
	if (cmd->cmd[1] && cmd->cmd[2])
		return (handle_error(EXIT_TOO_ARG, cmd->cmd[1]));
	if (cmd->cmd[1])
		g_exit_status = ft_atoi(cmd->cmd[1]);
	return (EXIT_SHELL);
}
