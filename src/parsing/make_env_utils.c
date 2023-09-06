/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:19:35 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/06 21:19:35 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	inc_shlvl(void *data)
{
	int		num_i;
	t_str	num_c;
	t_str	new_shlvl;

	new_shlvl = ft_strdup("SHLVL=");
	if (!new_shlvl)
		return (NULL);
	data += 6;
	num_i = ft_atoi(data);
	num_i++;
	num_c = ft_itoa(num_i);
	if (!num_c)
		return (NULL);
	new_shlvl = ft_strfjoin(new_shlvl, num_c);
	free(num_c);
	if (!new_shlvl)
		return (NULL);
	return (new_shlvl);
}
