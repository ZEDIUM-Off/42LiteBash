/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:10:11 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/29 20:10:11 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

int	lst_check(t_list **lst, t_str name)
{
	t_list	*tmp;
	t_uint	i;

	if (!lst || !name)
		return (handle_error(NULL_DATA, NULL));
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		if (ft_strnstr(tmp->data, name, ft_strlen(name)))
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
