/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:38:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/07 20:36:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	lst_remove(t_list **lst, t_uint index)
{
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return ;
	tmp = *lst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	if (tmp)
	{
		if (tmp->next)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
		g_shx->gc->free(tmp->data);
		g_shx->gc->free(tmp);
	}
}
void	lst_remove_first(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (tmp)
	{
		*lst = tmp->next;
		g_shx->gc->free(tmp->data);
		g_shx->gc->free(tmp);
	}
}
void	lst_remove_last(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (tmp)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		g_shx->gc->free(tmp->next->data);
		g_shx->gc->free(tmp->next);
		tmp->next = NULL;
	}
}