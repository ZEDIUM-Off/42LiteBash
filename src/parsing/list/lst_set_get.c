/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_set_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:43:36 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/14 19:36:47 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

void	*lst_get(t_list **lst, t_uint index)
{
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (NULL);
	tmp = *lst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	return (tmp->data);
}

t_uint	lst_get_index(t_list **lst, t_str name)
{
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (0);
	tmp = *lst;
	i = 0;
	printf("lst_get_index name = %s\n", name);
	while (tmp)
	{
		if (ft_strnstr(tmp->data, name, ft_strlen(name)))
			break ;
		tmp = tmp->next;
	}
	return (tmp->index);
}

void	lst_remplace(t_list **lst, t_uint index, t_str data)
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
		//free(tmp->data);
		tmp->data = ft_strdup(data);
	}
}

void	lst_set(t_list **lst, t_uint index, void *data)
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
		tmp->data = data;
}

t_list	*lst_get_first(t_list **lst)
{
	if (!lst)
		return (NULL);
	return (*lst);
}

t_list	*lst_get_last(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}