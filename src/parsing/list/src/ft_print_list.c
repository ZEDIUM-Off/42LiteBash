/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:05:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/05 15:25:00 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fonction_list.h"

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("content %s index [%d]\n", lst->argv, lst->index);
		lst = lst->next;
	}
	return ;
}
