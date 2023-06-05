/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:55:58 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/28 14:55:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fonction_list.h"

t_list	*ft_lstnew(char *argv)
{
	t_list			*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->argv = argv;
	lst->next = NULL;
	return (lst);
}
