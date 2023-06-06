/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delone_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:41:24 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/06 14:41:54 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fonction_list.h"

void	lst_delone_double(t_list **lst, t_list *del)
{
	if (!lst || !del)
		return ;
	if (del->prev)
		del->prev->next = del->next;
	else
		*lst = del->next;
	if (del->next)
		del->next->prev = del->prev;
	free(del);
}
