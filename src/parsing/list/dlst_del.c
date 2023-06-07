/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:52:38 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/07 20:31:57 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	dlst_remove(t_dlist **dlst, t_uint index)
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
	{
		if (tmp->next)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
		if (tmp->prev)
			tmp->prev = tmp->prev->prev;
		else
			tmp->prev = NULL;
		g_shx->gc->free(tmp->data);
		g_shx->gc->free(tmp);
	}
}

void	dlst_remove_first(t_dlist **dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return ;
	tmp = *dlst;
	if (tmp)
	{
		*dlst = tmp->next;
		(*dlst)->prev = NULL;
		g_shx->gc->free(tmp->data);
		g_shx->gc->free(tmp);
	}
}

void	dlst_remove_last(t_dlist **dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return ;
	tmp = *dlst;
	if (tmp)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		g_shx->gc->free(tmp->data);
		g_shx->gc->free(tmp);
	}
}
