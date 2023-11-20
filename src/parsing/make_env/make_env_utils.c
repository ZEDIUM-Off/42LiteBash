/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:19:35 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/20 17:24:23 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_str	inc_shlvl(t_sh_context *shx, void *data)
{
	int		num_i;
	t_str	num_c;
	t_str	new_shlvl;

	new_shlvl = ft_strdup(shx, "SHLVL=");
	if (!new_shlvl)
		return (NULL);
	data += 6;
	num_i = ft_atoi(data);
	num_i++;
	num_c = ft_itoa(shx, num_i);
	if (!num_c)
		return (NULL);
	new_shlvl = ft_strfjoin(shx, new_shlvl, num_c);
	// free(num_c);
	if (!new_shlvl)
		return (NULL);
	return (new_shlvl);
}
