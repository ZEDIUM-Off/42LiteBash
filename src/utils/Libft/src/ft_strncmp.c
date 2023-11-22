/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:14:47 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/22 11:15:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		a;
	int		b;

	i = 0;
	if (!s1[0] || !s2[0])
		return (-1);
	while (s1[i] && s2[i] && (i < n))
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
