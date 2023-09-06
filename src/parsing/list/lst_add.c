/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:31:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/06 20:01:38 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	lst_add_front(t_sh_context *shx, t_list **lst, void *data, t_uint index)
{
	t_list	*new;

	if (!lst)
		return (NULL_DATA);
	new = lst_create(shx, data, index);
	if (!new)
		return (MALLOC_FAIL);
	*lst = new;
	return (0);
}

t_uint	lst_add_back(t_sh_context *shx, t_list **lst, void *data, t_uint index)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL_DATA);
	new = lst_create(shx, data, index);
	if (!new)
		return (MALLOC_FAIL);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

t_uint	lst_insert(t_sh_context *shx, t_list **lst, void *data, t_uint index)
{
	t_list	*new;
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (NULL_DATA);
	new = lst_create(shx, data, index);
	if (!new)
		return (MALLOC_FAIL);
	if (!*lst)
		*lst = new;
	else
	{
		i = 0;
		tmp = *lst;
		while (tmp->next && i++ < index)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
	return (0);
}
