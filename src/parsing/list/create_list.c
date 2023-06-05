/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:59:00 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/05 15:25:57 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fonction_list.h"

// t_list	*make_list(t_data *data)
// {

// }

void	index_list_value(t_list *lst)
{
	t_list	*tmp_lst;
	t_list	*head;
	char	*tmp;
	int		index;

	tmp = lst->argv;
	head = lst;
	while (lst)
	{
		index = 0;
		tmp = lst->argv;
		tmp_lst = head;
		while (tmp_lst)
		{
			if (tmp > tmp_lst->argv)
				index++;
			tmp_lst = tmp_lst->next;
		}
		lst->index = index;
		lst = lst->next;
	}
	return ;
}
