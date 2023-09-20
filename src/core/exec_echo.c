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

	j = 0;
	while ((*tmp)->txt[j])
		echo_builtins((*tmp)->txt[j++]);
	while (*i <= (*tmp)->end)
		(*i)++;
	*tmp = (*tmp)->next;
}

t_uint	exec_echo(t_cmd **_cmd)
{
	bool	n;
	t_uint	i;
	t_chunk	*tmp;

	n = 0;
	i = 1;
	if (!(*_cmd)->cmd[i] || (*_cmd)->cmd[i][0] == '\0')
		return (1);
	tmp = (*_cmd)->chunk;
	while ((*_cmd)->cmd[i] != NULL)
	{
		if (ft_strnstr((*_cmd)->cmd[i], "-n",
				ft_strlen((*_cmd)->cmd[i])))
		{
			printf("PASS in -n exec_echo\n");
			n = 1;
			i++;
		}
		if (tmp)
			handle_chunck(&tmp, &i);
		if ((*_cmd)->cmd[i])
			printf("%s", (*_cmd)->cmd[i]);
		if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i][0] != '\0')
			printf(" ");
		i++;
	}
	if (n == 0)
		printf("\n");
	return (CONTINUE_PROC);
}
