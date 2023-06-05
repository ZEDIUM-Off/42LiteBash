/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:39:25 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/21 15:55:45 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, ssize_t n)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (free(s1), NULL);
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!str)
		return (clear_buff(s2), free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	k = 0;
	while (s2[k] && k <= n)
		str[i++] = s2[k++];
	return (str[i] = '\0', free(s1), str);
}

ssize_t	ft_strchr_gnl(char *s, int c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
