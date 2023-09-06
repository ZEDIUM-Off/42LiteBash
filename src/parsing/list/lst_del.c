/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:38:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/06 20:01:38 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	lst_remove(t_sh_context *shx, t_list **lst, t_uint index)
{
	t_list	*current;
	t_list	*previous;

	current = *lst;
	previous = NULL;
	if (!lst)
		return (NULL_DATA);
	while (current != NULL)
	{
		if (current->index == index)
		{
			if (previous == NULL)
					*lst = current->next;
			else
				previous->next = current->next;
			shx->gc->free(shx, current->data);
			shx->gc->free(shx, current);
			return (0);
		}
		previous = current;
		current = current->next;
	}
	return (0);
}
t_uint	lst_remove_first(t_sh_context *shx, t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL_DATA);
	tmp = *lst;
	if (tmp)
	{
		*lst = tmp->next;
		shx->gc->free(shx, tmp->data);
		shx->gc->free(shx, tmp);
	}
	return (0);
}
t_uint	lst_remove_last(t_sh_context *shx, t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL_DATA);
	tmp = *lst;
	if (tmp)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		shx->gc->free(shx, tmp->next->data);
		shx->gc->free(shx, tmp->next);
		tmp->next = NULL;
	}
	return (0);
}
