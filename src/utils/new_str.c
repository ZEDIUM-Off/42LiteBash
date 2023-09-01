/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:35:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/08/31 15:29:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	new_str(t_sh_context *shx, t_str str)
{
	t_str	new_str;

	new_str = shx->gc->malloc(
			shx, sizeof(t_str) * (ft_strlen(str) + 1), false);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str, ft_strlen(str) + 1);
	return (new_str);
}
