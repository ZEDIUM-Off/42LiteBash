/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:39:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/08 17:23:01 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_free_tab(void *tab, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(((char **)tab)[i]);
		i++;
	}
	free(tab);
	return ;
}
