/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:52:38 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 14:35:26 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	dlst_remove(t_sh_context *shx, t_dlist **dlst, t_uint index)
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
		shx->gc->free(shx, tmp->data);
		shx->gc->free(shx, tmp);
	}
}

void	dlst_remove_first(t_sh_context *shx, t_dlist **dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return ;
	tmp = *dlst;
	if (tmp)
	{
		*dlst = tmp->next;
		(*dlst)->prev = NULL;
		shx->gc->free(shx, tmp->data);
		shx->gc->free(shx, tmp);
	}
}

void	dlst_remove_last(t_sh_context *shx, t_dlist **dlst)
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
		shx->gc->free(shx, tmp->data);
		shx->gc->free(shx, tmp);
	}
}
