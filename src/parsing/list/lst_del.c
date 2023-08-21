/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:38:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/21 17:15:15 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	lst_remove(t_list **lst, t_uint index)
{
 	t_list *current;
    t_list *previous;

	current = *lst;
	previous = NULL;
    if (!lst)
        return;
   while (current != NULL)
    {
        if (current->index == index)
        {
            if (previous == NULL)
            {
                *lst = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            g_shx->gc->free(current->data);
            g_shx->gc->free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
	return ;
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