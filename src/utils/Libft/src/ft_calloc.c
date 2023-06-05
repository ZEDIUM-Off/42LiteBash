/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:05:05 by bfaure            #+#    #+#             */
/*   Updated: 2022/11/17 15:05:05 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (count != 0 && SIZE_MAX / count < size)
		return (NULL);
	len = size * count;
	ptr = malloc (len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (len--)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *) ptr);
}
