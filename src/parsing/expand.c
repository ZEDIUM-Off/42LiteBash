/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:30:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/31 14:28:39 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

// static bool	check_expand(t_str *to_exp, t_uint j, t_list *tmp, bool found)
// {
// 	if (!ft_strncmp(&(*to_exp)[1], tmp->data, j)
// 	&& ft_strlen(&(*to_exp)[1]) == j)
// 	{
// 		found = true;
// 		*to_exp = ft_strdup(&((char *)tmp->data)[++j]);
// 		if (!*to_exp)
// 			return (false);
// 	}
// 	return (found);
// }

void	expand(t_str *to_exp)
{
	t_uint	j;
	bool	found;
	t_list	*tmp;

	tmp = g_shx->envp;
	// found = false;
	while (tmp)
	{
		j = 0;
		while (((t_str)(tmp->data))[j] != '=')
			j++;
		// found = check_expand(to_exp, j, tmp, found);
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

void	chunck_expand(t_chunk **chunk)
{
	t_uint	i;

	if ((*chunk)->type == DOUBLE_QUOTE)
	{
		i = 0;
		while ((*chunk)->txt[i])
		{
			if (get_meta_char(&(*chunk)->txt[i][0]) == DOLLAR
				&& (*chunk)->txt[i][1] != '\0')
				expand(&(*chunk)->txt[i]);
			i++;
		}
	}
}

void	cmd_expand(t_cmd **cmd)
{
	t_uint	i;
	t_chunk	*tmp;

	i = 0;
	tmp = (*cmd)->chunk;
	while ((*cmd)->cmd[i])
	{
		if (tmp && i == tmp->start)
		{
			chunck_expand(&tmp);
			while (i < tmp->end)
				i++;
			tmp = tmp->next;
		}
		if (get_meta_char(&(*cmd)->cmd[i][0]) == DOLLAR
			&& (*cmd)->cmd[i][1] != '\0')
			expand(&(*cmd)->cmd[i]);
		i++;
	}
}
