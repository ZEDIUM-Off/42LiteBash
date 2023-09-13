/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:15:42 by bfaure            #+#    #+#             */
/*   Updated: 2022/11/18 11:15:42 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strfjoin(t_sh_context *shx, char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	str = shx->gc->malloc(shx, sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2)) + 1, true);
	if (!str)
		return (shx->gc->free(shx, s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	k = 0;
	while (s2[k])
		str[i++] = s2[k++];
	return (str[i] = '\0', shx->gc->free(shx, s1), str);
}
