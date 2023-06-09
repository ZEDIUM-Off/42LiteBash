/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_set_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:55:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/09 09:59:17 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_dlist	*dlst_get(t_dlist **dlst, t_uint index)
{
	t_dlist	*tmp;
	t_uint	i;

	if (!dlst)
		return (NULL);
	tmp = *dlst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	return (tmp);
}

void	dlst_set(t_dlist **dlst, t_uint index, void *data)
{
	t_dlist	*tmp;
	t_uint	i;

	if (!dlst)
		return ;
	tmp = *dlst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	if (tmp)
		tmp->data = data;
}

t_dlist	*dlst_get_first(t_dlist **dlst)
{
	if (!dlst)
		return (NULL);
	return (*dlst);
}

t_dlist	*dlst_get_last(t_dlist **dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return (NULL);
	tmp = *dlst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
