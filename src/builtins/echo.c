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

bool	check_backslash(t_cmd **_cmd, t_uint *i, bool *n)
{
	if (ft_strnstr((*_cmd)->cmd[*i], "-n", ft_strlen((*_cmd)->cmd[*i]))
		&& ((*_cmd)->cmd[*i][2] == ' ' || (*_cmd)->cmd[*i][2] == '\0'))
	{
		*n = 1;
		*i += 1;
		return (true);
	}
	return (false);
}

t_uint	exec_echo(t_cmd **_cmd)
{
	bool	n;
	t_uint	i;

	n = 0;
	i = 1;
	if (!(*_cmd)->cmd[i] || (*_cmd)->cmd[i][0] == '\0')
		return (printf("\n") && CONTINUE_PROC);
	while ((*_cmd)->cmd[i])
	{
		if (i == 1 && n == 0 && check_backslash(_cmd, &i, &n))
			continue ;
		printf("%s", (*_cmd)->cmd[i]);
		if ((*_cmd)->cmd[++i])
			printf(" ");
	}
	if (n == 0)
		printf("\n");
	return (CONTINUE_PROC);
}
