/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:39:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/08 20:20:58 by aviscogl         ###   ########lyon.fr   */
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

void	ft_free_tab(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return ;
}
