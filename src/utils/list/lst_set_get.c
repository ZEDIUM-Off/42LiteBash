/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_set_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:43:36 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/06 11:33:26 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>
#include <string.h>

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

int	lst_get_index(t_list **lst, t_str name)
{
	t_list	*tmp;
	t_uint	i;

	if (!*lst || !name)
		return (-1);
	i = 0;
	tmp = *lst;
	while (tmp && tmp->data)
	{
		if (ft_strnstr((t_str)tmp->data, name, ft_strlen(name)))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

t_uint	lst_set(t_list **lst, t_uint index, void *data)
{
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (handle_error(NULL_DATA, NULL));
	tmp = *lst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	if (tmp)
		tmp->data = data;
	return (CONTINUE_PROC);
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
