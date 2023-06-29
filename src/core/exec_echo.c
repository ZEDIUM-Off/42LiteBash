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
	t_uint	j;
	t_chunk	*tmp;

	n = 0;
	i = 1;
	trace("exec_echo", "exec echo cmd", EXEC);
	tmp = (*_cmd)->chunk;
	while ((*_cmd)->cmd[i])
	{
		if (ft_strncmp((*_cmd)->cmd[i], "-n",
				ft_strlen((*_cmd)->cmd[i])) == 0)
		{
			n = 1;
			i++;
		}
		if (tmp && i == tmp->start - 1)
		{
			j = 0;
			while (tmp->txt[j])
				echo_builtins(tmp->txt[j++]);
			while (i <= tmp->end)
				i++;
			tmp = tmp->next;
		}
		else
		{
			echo_builtins((*_cmd)->cmd[i]);
			i++;
		}
		printf(" ");
	}
	if (n == 0)
		printf("\n");
	log_action();
	return (0);
}
