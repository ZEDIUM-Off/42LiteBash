/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:49:07 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/07 20:03:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	dlst_add_front(t_dlist **dlst, void *data)
{
	t_dlist	*new;

	if (!dlst)
		return ;
	new = dlst_create(data);
	new->next = *dlst;
	(*dlst)->prev = new;
	*dlst = new;
}
void	dlst_add_back(t_dlist **dlst, void *data)
{
	t_dlist	*new;
	t_dlist	*tmp;

	if (!dlst)
		return ;
	new = dlst_create(data);
	if (!*dlst)
		*dlst = new;
	else
	{
		tmp = *dlst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	dlst_insert(t_dlist **dlst, void *data, t_uint index)
{
	t_dlist	*new;
	t_dlist	*tmp;
	t_uint	i;

	if (!dlst)
		return ;
	new = dlst_create(data);
	if (!*dlst)
		*dlst = new;
	else
	{
		i = 0;
		tmp = *dlst;
		while (tmp->next && i++ < index)
			tmp = tmp->next;
		new->next = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}
