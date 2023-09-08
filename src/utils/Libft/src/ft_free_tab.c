/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:39:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/08 14:07:06 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_free_tab_len(char **strs, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return ;
}

void	ft_free_tab(t_sh_context *shx, char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		shx->gc->free(shx, strs[i]);
		i++;
	}
	shx->gc->free(shx, strs);
	return ;
}
