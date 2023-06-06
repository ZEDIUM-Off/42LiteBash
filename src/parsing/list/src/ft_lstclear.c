/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:04:51 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/06 15:06:50 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fonction_list.h"

void	ft_lstclear_double(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	return ;
}
