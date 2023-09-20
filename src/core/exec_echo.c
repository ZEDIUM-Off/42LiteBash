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

static void	echo_chunck(t_cmd **cmd, t_chunk **tmp, t_uint *i)
{
	t_uint				j;

	j = 0;
	while ((*tmp)->txt[j] && get_meta_char((*tmp)->txt[j]) != (*tmp)->type)
	{
		printf("%s", (*tmp)->txt[j]);
		j++;
	}
	if ((*cmd)->cmd[(*tmp)->end + 1])
		*i = (*tmp)->end + 1;
	else
		*i = (*tmp)->end; 
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
	while ((*_cmd)->cmd[i] && (*_cmd)->cmd[i] != NULL )
	{
		if (ft_strnstr((*_cmd)->cmd[i], "-n",
				ft_strlen((*_cmd)->cmd[i])))
		{
			printf("PASS in -n exec_echo\n");
			n = 1;
			i++;
		}
		if (tmp)
			echo_chunck(_cmd, &tmp, &i);
		if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i][0] == '\0' && (*_cmd)->cmd[i + 1])
			i++;
		if ((*_cmd)->cmd[i] && get_meta_char((*_cmd)->cmd[i]) != DOUBLE_QUOTE)
			printf("%s", (*_cmd)->cmd[i]);
		if ((*_cmd)->cmd[i] && (*_cmd)->cmd[i][0] != '\0')
			printf(" ");
		i++;
	}
	if (n == 0)
		printf("\n");
	return (CONTINUE_PROC);
}
