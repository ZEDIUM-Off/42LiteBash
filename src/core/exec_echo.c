/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:37:37 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/28 15:37:37 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint  exec_echo(void)
{
    while (g_shx->blocks->ppl)
    {
        if (ft_strncmp(g_shx->blocks->ppl->cmd->cmd[0], "echo", ft_strlen(g_shx->blocks->ppl->cmd->cmd[0])) == 0)
            echo_builtins(g_shx->blocks->ppl->cmd->cmd);
        g_shx->blocks->ppl = g_shx->blocks->ppl->next;
    }
    return (0);
}