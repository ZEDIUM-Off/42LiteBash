/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:24:47 by bfaure            #+#    #+#             */
/*   Updated: 2023/08/21 17:24:47 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	index_list_value(t_list **lst)
{
	t_list	*tmp;
	t_uint	index;

	if (!lst)
		return (NULL_DATA);
	tmp = *lst;
	index = 0;
	while (tmp)
	{
		tmp->index = index++;
		tmp = tmp->next;
	}
	return (0);
}
