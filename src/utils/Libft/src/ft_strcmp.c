/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:50:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/11/06 10:50:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		a;
	int		b;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			a = (((unsigned char *)s1)[i] + '0');
			b = (((unsigned char *)s2)[i] + '0');
			return (a - b);
		}
		i++;
	}
	return (0);
}
