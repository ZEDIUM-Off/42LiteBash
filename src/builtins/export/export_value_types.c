/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_value_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:40:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/17 11:03:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

bool	last_cmd_cond(t_cmd **_cmd, t_chunk **chunk, t_uint *i)
{
	return (
		(*_cmd)->cmd[*i] && (*_cmd)->cmd[*i][0] != '\0'
		&& (!*chunk || (*chunk)->start != *i + 1)
		&& (!((*_cmd)->cmd[*i + 1]) || (*_cmd)->cmd[*i + 1][0] != '\0')
	);
}

t_uint	handle_inner_cmd(t_cmd **_cmd,
	t_export *to_export, t_uint *i)
{
	if ((*_cmd)->cmd[*i] && (*_cmd)->cmd[*i + 1]
		&& (*_cmd)->cmd[*i + 1][0] == '\0')
	{
		to_export->value = ft_strjoin((*_cmd)->shx,
				to_export->value, (*_cmd)->cmd[*i]);
		if (to_export->value == NULL)
			return (handle_error(MALLOC_FAIL, NULL));
		*i += 2;
	}
	return (CONTINUE_PROC);
}

int	last_cmd(t_cmd **_cmd, t_chunk **chunk, t_export *to_export, t_uint *i)
{
	if (last_cmd_cond(_cmd, chunk, i))
	{
		to_export->value = ft_strjoin((*_cmd)->shx,
				to_export->value, (*_cmd)->cmd[*i]);
		if (to_export->value == NULL)
			return (handle_error(MALLOC_FAIL, NULL));
		*i += 1;
		return (-1);
	}
	return (CONTINUE_PROC);
}

t_uint	handle_chunk(t_cmd **_cmd, t_chunk **chunk,
	t_export *to_export, t_uint *i)
{
	t_uint	j;

	j = 0;
	while ((*chunk) && (*chunk)->txt[j])
	{
		to_export->value = ft_strjoin((*_cmd)->shx,
				to_export->value, (*chunk)->txt[j]);
		if (to_export->value == NULL)
			return (handle_error(MALLOC_FAIL, NULL));
		j++;
	}
	*i = (*chunk)->end + 1;
	(*chunk) = (*chunk)->next;
	return (CONTINUE_PROC);
}

t_uint	get_value(t_cmd **_cmd, t_chunk **chunk,
	t_export *to_export, t_uint *i)
{
	int	status;

	*i += 2;
	while ((*_cmd)->cmd[*i])
	{
		if ((*_cmd)->cmd[*i] && (*_cmd)->cmd[*i][0] == '\0')
			*i += 1;
		if ((*chunk) && (*chunk)->start == *i + 1)
		{
			status = handle_chunk(_cmd, chunk, to_export, i);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			if (!(*_cmd)->cmd[*i] || (*_cmd)->cmd[*i][0] != '\0')
				break ;
		}
		status = handle_inner_cmd(_cmd, to_export, i);
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
		status = last_cmd(_cmd, chunk, to_export, i);
		if (status == -1)
			break ;
		if (status != CONTINUE_PROC)
			return (handle_error(status, NULL));
	}
	return (CONTINUE_PROC);
}
