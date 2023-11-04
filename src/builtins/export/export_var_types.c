/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:34:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/04 09:39:05 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

typedef struct s_exp_utils
{
	t_str	tmp;
	bool	process;
}		t_exp_utils;

t_uint	handle_plus_equal(t_cmd **_cmd, t_chunk **chunk,
	t_export *to_export, t_uint *i)
{
	t_uint		status;

	*i += 1;
	if (to_export->name == NULL)
		return (handle_error(EXPORT_NOT_VALID_ID, (*_cmd)->cmd[*i]));
	else
	{
		to_export->type = get_meta_char((*_cmd)->cmd[*i]);
		if ((*_cmd)->cmd[*i + 1] && (*_cmd)->cmd[*i + 1][0] == '\0')
		{
			status = get_value(_cmd, chunk, to_export, i);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
		else
			*i += 1;
	}
	return (CONTINUE_PROC);
}

t_uint	handle_var(t_cmd **_cmd, t_chunk **chunk,
		t_export *to_export, t_uint *i)
{
	t_uint		status;
	t_str		tmp;

	tmp = NULL;
	if (to_export->name)
		tmp = ft_strdup((*_cmd)->shx, to_export->name);
	tmp = ft_strfjoin((*_cmd)->shx, tmp, (*_cmd)->cmd[*i]);
	status = check_var((*_cmd)->shx, tmp, to_export);
	if (status != CONTINUE_PROC)
		return (handle_error(status, NULL));
	printf ("hv cmd[%d] = %s\n", *i, (*_cmd)->cmd[*i]);
	if ((*_cmd)->cmd[*i + 1] && (*_cmd)->cmd[*i + 1][0] == '\0')
	{
		if ((*_cmd)->cmd[*i + 2] && (*_cmd)->cmd[*i + 2][0] != '='
			&& (*_cmd)->cmd[*i + 2][0] != '+'
			&& (*chunk) && (*chunk)->start == *i + 3)
			return (handle_chunk_var(chunk, _cmd, to_export, i));
		else
			*i += 1;
	}
	else
		*i += 1;
	return (CONTINUE_PROC);
}

t_uint	look_after(t_cmd **_cmd, t_chunk **chunk, t_uint *i, t_exp_utils *utils)
{
	if ((*_cmd)->cmd[*i] && (*_cmd)->cmd[*i][0] == '\0')
	{
		if ((*_cmd)->cmd[*i + 1] && ((*_cmd)->cmd[*i + 1][0] == '+'
			|| (*_cmd)->cmd[*i + 1][0] == '='))
			utils->process = false;
		else if (*i + 2 != (*chunk)->start)
		{
			utils->tmp = ft_strfjoin((*_cmd)->shx,
					utils->tmp, (*_cmd)->cmd[*i + 1]);
			if (!utils->tmp)
				return (handle_error(MALLOC_FAIL, NULL));
			*i += 2;
		}
	}
	else
		utils->process = false;
	return (CONTINUE_PROC);
}

t_uint	handle_chunk_var(t_chunk **chunk, t_cmd **_cmd,
		t_export *to_export, t_uint *i)
{
	t_exp_utils	utils;

	*i = (*chunk)->start;
	utils.process = true;
	utils.tmp = NULL;
	if (to_export->name)
		utils.tmp = ft_strdup((*_cmd)->shx, to_export->name);
	while ((*chunk) && utils.process && (*_cmd)->cmd[*i])
	{
		if (*i == (*chunk)->start || *i + 2 == (*chunk)->start)
		{
			if ((*chunk)->txt && (*chunk)->txt[0] && (*chunk)->txt[1] != NULL)
				return (handle_error(EXPORT_NOT_VALID_ID, (*chunk)->txt[1]));
			utils.tmp = ft_strfjoin((*_cmd)->shx, utils.tmp, (*chunk)->txt[0]);
			if (!utils.tmp)
				return (handle_error(MALLOC_FAIL, NULL));
			*i = (*chunk)->end + 1;
			(*chunk) = (*chunk)->next;
		}
		if (look_after(_cmd, chunk, i, &utils) != CONTINUE_PROC)
			return (handle_error(EXIT_SHELL, NULL));
	}
	return (check_var((*_cmd)->shx, utils.tmp, to_export));
}
