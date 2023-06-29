/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:36:20 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/27 23:36:20 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint echo_builtins(t_str *splited)
{
	t_uint	i;

	if (!splited)
		return (1);
	i = 0;
	while (splited[i])
	{
		printf("%s", splited[i]);
		i++;
	}
	return (0);
}