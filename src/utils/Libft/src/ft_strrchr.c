/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:51:06 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/12 14:00:59 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	size_t	len;

	s1 = (char *) s;
	len = ft_strlen(s1);
	c = (char) c;
	while (len + 1)
	{
		if (s1[len] == c)
			return (&s1[len]);
		len--;
	}
	return (NULL);
}
