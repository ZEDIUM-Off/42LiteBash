/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:31:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/17 09:27:07 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	lst_add_front(t_sh_context *shx, t_list **lst, void *data)
{
	t_list	*new;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	new = lst_create(shx, data);
	if (!new)
		return (handle_error(MALLOC_FAIL, NULL));
	new->next = *lst;
	*lst = new;
	return (CONTINUE_PROC);
}

t_uint	lst_add_back(t_sh_context *shx, t_list **lst, void *data)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	new = lst_create(shx, data);
	if (!new)
		return (handle_error(MALLOC_FAIL, NULL));
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (CONTINUE_PROC);
}

t_uint	lst_insert(t_sh_context *shx, t_list **lst, void *data, t_uint index)
{
	t_list	*new;
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	new = lst_create(shx, data);
	if (!new)
		return (handle_error(MALLOC_FAIL, NULL));
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
	return (CONTINUE_PROC);
}

t_uint	lst_append(t_sh_context *shx, t_list **lst, t_uint index, t_str data)
{
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	if (!data)
		return (handle_error(NULL_DATA, NULL));
	tmp = *lst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	if (tmp)
	{
		tmp->data = ft_strfjoin(shx, tmp->data, data);
		if (!tmp->data)
			return (handle_error(MALLOC_FAIL, NULL));
	}
	return (CONTINUE_PROC);
}
