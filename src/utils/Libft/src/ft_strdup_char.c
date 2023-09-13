/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:20:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/09/07 14:34:34 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strcpy(char *dst, const char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup_char(t_sh_context *shx, const char *str, char c)
{
	char	*dest;

	dest = shx->gc->malloc(shx, sizeof(char) * (ft_strlen(str) + 1), false);
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, str, c));
}
