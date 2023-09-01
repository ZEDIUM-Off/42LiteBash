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

t_uint	echo_builtins(t_sh_context *shx, t_str cmd)
{
	trace(shx, "echo_builtins", "the cmd echo", EXEC);
	if (!cmd)
		return (1);
	printf("%s", cmd);
	return (0);
}
