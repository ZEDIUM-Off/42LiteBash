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

static void	handle_chunk(t_chunk **tmp, t_uint *i)
{
	t_uint				j;
	t_sh_context	*shx;

	shx = (*tmp)->shx;
	j = 0;
	while ((*tmp)->txt[j])
		echo_builtins(shx, (*tmp)->txt[j++]);
	while (*i <= (*tmp)->end)
		(*i)++;
	*tmp = (*tmp)->next;
}

static void	handle_cmd(t_cmd **_cmd, t_uint *i)
{
	t_sh_context	*shx;

	shx = (*_cmd)->shx;
	echo_builtins(shx, (*_cmd)->cmd[*i]);
	(*i)++;
}

t_uint	exec_echo(t_cmd **_cmd)
{
	bool	n;
	t_uint	i;
	t_chunk	*tmp;
	t_sh_context	*shx;

	shx = (*_cmd)->shx;
	n = 0;
	i = 1;
	trace(shx, "exec_echo", "exec echo cmd", EXEC);
	if ((*_cmd)->cmd[i][0] == '\0')
		return (1);
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
			handle_chunk(&tmp, &i);
		else
			handle_cmd(_cmd, &i);
		printf(" ");
	}
	if (n == 0)
		printf("\n");
	log_action(shx);
	return (0);
}
