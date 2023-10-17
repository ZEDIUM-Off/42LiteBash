/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:28:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/10/16 19:48:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

char	*ft_strinstert(t_sh_context *shx, char *src, char *to_insert, int index)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!src || !to_insert)
		return (NULL);
	new = shx->gc->malloc(shx, sizeof(char)
			* (ft_strlen(src) + ft_strlen(to_insert) + 1), false);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (src[i] && i < index)
		new[j++] = src[i++];
	k = 0;
	while (to_insert[k])
		new[j++] = to_insert[k++];
	while (src[i])
		new[j++] = src[i++];
	new[j] = '\0';
	return (new);
}
