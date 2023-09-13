/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:13:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/22 23:13:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(t_sh_context *shx, char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = shx->gc->malloc(shx, sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1), true);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
