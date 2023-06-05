/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:42:55 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/12 14:00:51 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	size_t	len;

	s1 = (char *) s;
	len = ft_strlen(s1);
	while (len + 1)
	{
		if (*(unsigned char *)s1 == (unsigned char)c)
			return (s1);
		s1++;
		len--;
	}
	return (NULL);
}
