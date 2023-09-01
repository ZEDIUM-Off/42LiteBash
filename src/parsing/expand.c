/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/31 16:15:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	expand(t_sh_context *shx, t_str *to_exp)
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
			*to_exp = ft_strdup(&((char *)tmp->data)[++j]);
			if (!*to_exp)
				return ;
		}
		tmp = tmp->next;
	}
	if (!found)
	{
		*to_exp = ft_strdup("");
		if (!*to_exp)
			return ;
	}
}

void	chunck_expand(t_sh_context *shx, t_chunk **chunk)
{
	t_uint	i;

	if ((*chunk)->type == DOUBLE_QUOTE)
	{
		i = 0;
		while ((*chunk)->txt[i])
		{
			if (get_meta_char(&(*chunk)->txt[i][0]) == DOLLAR
				&& (*chunk)->txt[i][1] != '\0')
				expand(shx, &(*chunk)->txt[i]);
			i++;
		}
	}
}

void	cmd_expand(t_sh_context *shx, t_cmd **cmd)
{
	t_uint	i;
	t_chunk	*tmp;

	i = 0;
	tmp = (*cmd)->chunk;
	while ((*cmd)->cmd[i])
	{
		if (tmp && i == tmp->start)
		{
			chunck_expand(shx, &tmp);
			while (i < tmp->end)
				i++;
			tmp = tmp->next;
		}
		if (get_meta_char(&(*cmd)->cmd[i][0]) == DOLLAR
			&& (*cmd)->cmd[i][1] != '\0')
			expand(shx, &(*cmd)->cmd[i]);
		i++;
	}
}
