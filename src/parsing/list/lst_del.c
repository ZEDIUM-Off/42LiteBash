/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:38:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:27:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	lst_remove(t_sh_context *shx, t_list **lst, t_uint index)
{
	t_list	*current;
	t_list	*previous;

	current = *lst;
	previous = NULL;
	if (!lst)
		return ;
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
			return ;
		}
		previous = current;
		current = current->next;
	}
	return ;
}
void	lst_remove_first(t_sh_context *shx, t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (tmp)
	{
		*lst = tmp->next;
		shx->gc->free(shx, tmp->data);
		shx->gc->free(shx, tmp);
	}
}
void	lst_remove_last(t_sh_context *shx, t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (tmp)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		shx->gc->free(shx, tmp->next->data);
		shx->gc->free(shx, tmp->next);
		tmp->next = NULL;
	}
}
