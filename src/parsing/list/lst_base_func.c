/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_base_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/14 17:44:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_list	*lst_create(void *data, t_uint index)
{
	t_list	*new;

	new = g_shx->gc->malloc(sizeof(t_list), true);
	if (!new)
		return (NULL);
	new->data = data;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	lst_print(t_list **lst, t_str text)

{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf(text, tmp->index, tmp->data);
		tmp = tmp->next;
	}
}

void	lst_clear(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		g_shx->gc->free(tmp->data);
		g_shx->gc->free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}

t_uint	lst_size(t_list **lst)
{
	t_list	*tmp;
	t_uint	i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
