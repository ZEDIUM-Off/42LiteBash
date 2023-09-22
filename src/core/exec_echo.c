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

static void	echo_chunck(t_chunk **tmp, t_uint *i)
{
	t_uint				j;

	j = 0;
	while ((*tmp)->txt[j])
	{
		if (get_meta_char((*tmp)->txt[j]) != (*tmp)->type)
			printf("%s", (*tmp)->txt[j]);
		j++;
	}
	*i = (*tmp)->end + 1;
	*tmp = (*tmp)->next;
}

bool	check_backslash(t_cmd **_cmd, t_uint *i, bool *n)
{
	bool	find;

	find = false;
	if (ft_strnstr((*_cmd)->cmd[*i], "-n", ft_strlen((*_cmd)->cmd[*i]))
		&& ((*_cmd)->cmd[*i][2] == ' ' || (*_cmd)->cmd[*i][2] == '\0'))
	{
		find = true;
		*n = 1;
		*i += 1;
	}
	return (find);
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
	while ((*_cmd)->cmd[i] && (*_cmd)->cmd[i] != NULL)
	{
		if (check_backslash(_cmd, &i, &n))
			continue ;
		else if (tmp && i + 1 == tmp->start)
			echo_chunck(&tmp, &i);
		else
		{
			if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i][0] == '\0')
				i++;
			if ((*_cmd)->cmd[i])
				printf("%s", (*_cmd)->cmd[i]);
			i++;
		}
		if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i][0] != '\0')
			printf(" ");
	}
	if (n == 0)
		printf("\n");
	return (CONTINUE_PROC);
}
