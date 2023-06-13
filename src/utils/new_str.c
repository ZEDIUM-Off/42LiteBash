/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:35:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/13 15:19:57 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	new_str(t_str str)
{
	t_str	new_str;

	new_str = g_shx->gc->malloc(sizeof(t_str) * (ft_strlen(str) + 1), false);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str, ft_strlen(str) + 1);
	return (new_str);
}
