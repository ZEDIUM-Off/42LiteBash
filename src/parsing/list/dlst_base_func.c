/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_base_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/13 15:20:26 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_dlist	*dlst_create(void *data)
{
	t_dlist	*new;

	new = g_shx->gc->malloc(sizeof(t_dlist), true);
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	dlst_print(t_dlist **dlst, t_str text)
{
	t_dlist	*tmp;

	tmp = *dlst;
	while (tmp)
	{
		printf(text, tmp->data);
		tmp = tmp->next;
	}
}

void	dlst_clear(t_dlist **dlst)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = *dlst;
	while (tmp)
	{
		tmp2 = tmp->next;
		g_shx->gc->free(tmp->data);
		g_shx->gc->free(tmp);
		tmp = tmp2;
	}
	*dlst = NULL;
}

t_uint	dlst_size(t_dlist **dlst)
{
	t_dlist	*tmp;
	t_uint	i;

	i = 0;
	tmp = *dlst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
