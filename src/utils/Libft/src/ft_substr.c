/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:52:44 by bfaure            #+#    #+#             */
/*   Updated: 2022/11/17 21:52:44 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static char	*ft_cpy(char *dst, const char *src, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (src[start] != '\0' && i < len)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(&s[start]))
		dest = malloc(sizeof(char) * (len + 1));
	else
		dest = malloc(sizeof(char) * (ft_strlen(&s[start]) + 1));
	if (!dest)
		return (NULL);
	return (ft_cpy(dest, s, start, len));
}
