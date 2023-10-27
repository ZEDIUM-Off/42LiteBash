/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/10/27 12:09:58 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	expand(t_sh_context *shx, t_str *to_exp)
{
	t_uint	j;
	bool	found;
	t_list	*tmp;

	tmp = shx->envp;
	while (tmp)
	{
		j = 0;
		while (((t_str)(tmp->data))[j] != '=')
			j++;
		if (!ft_strncmp(&(*to_exp)[1], tmp->data, j)
			&& ft_strlen(&(*to_exp)[1]) == j)
		{
			found = true;
			*to_exp = ft_strdup(shx, &((char *)tmp->data)[++j]);
			if (!*to_exp)
				return (handle_error(MALLOC_FAIL, NULL));
		}
		tmp = tmp->next;
	}
	if (!found)
	{
		*to_exp = ft_strdup(shx, "");
		if (!*to_exp)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	return (CONTINUE_PROC);
}

t_uint	chunck_expand(t_sh_context *shx, t_chunk **chunk)
{
	t_uint	i;
	t_uint	status;

	if ((*chunk)->type == DOUBLE_QUOTE)
	{
		i = 0;
		while ((*chunk)->txt[i])
		{
			if (get_meta_char(&(*chunk)->txt[i][0]) == DOLLAR
				&& (*chunk)->txt[i][1] != '\0')
			{
				status = expand(shx, &(*chunk)->txt[i]);
				if (status != CONTINUE_PROC)
					return (handle_error(status, NULL));
			}
			i++;
		}
	}
	return (CONTINUE_PROC);
}

t_uint	cmd_expand(t_sh_context *shx, t_cmd **cmd)
{
	t_uint	i;
	t_uint	status;
	t_chunk	*tmp;

	i = 0;
	tmp = (*cmd)->chunk;
	while ((*cmd)->cmd[i])
	{
		if (tmp && i == tmp->start)
		{
			status = chunck_expand(shx, &tmp);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
			while (i < tmp->end)
				i++;
			tmp = tmp->next;
		}
		if (get_meta_char(&(*cmd)->cmd[i][0]) == DOLLAR)
		{
			status = expand(shx, &(*cmd)->cmd[i]);
			if (status != CONTINUE_PROC)
				return (handle_error(status, NULL));
		}
		else if (get_meta_char(&(*cmd)->cmd[i][0]) == DOLLAR_Q)
		{
			(*cmd)->cmd[i] = ft_itoa(g_exit_status);
			if (!(*cmd)->cmd[i])
				return (handle_error(MALLOC_FAIL, NULL));
		}
		i++;
	}
	return (CONTINUE_PROC);
}
