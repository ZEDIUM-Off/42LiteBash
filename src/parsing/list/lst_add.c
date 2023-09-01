/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:31:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:25:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	lst_add_front(t_sh_context *shx, t_list **lst, void *data, t_uint index)
{
	t_list	*new;

	if (!lst)
		return ;
	new = lst_create(shx, data, index);
	*lst = new;
}

void	lst_add_back(t_sh_context *shx, t_list **lst, void *data, t_uint index)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return ;
	new = lst_create(shx, data, index);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	lst_insert(t_sh_context *shx, t_list **lst, void *data, t_uint index)
{
	t_list	*new;
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return ;
	new = lst_create(shx, data, index);
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
}
