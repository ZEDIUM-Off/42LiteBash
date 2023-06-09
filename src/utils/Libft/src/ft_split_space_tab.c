/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:59:38 by bfaure            #+#    #+#             */
/*   Updated: 2023/06/09 08:55:05 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_count_words(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			count++;
			while ((str[i] != ' ' && str[i] != '\t') && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_str_cut(char **dest, char const *src)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (src[i] && ft_count_words(src) - k > 0)
	{
		while (src[i] && (src[i] == ' ' || src[i] == '\t'))
			i++;
		j = i;
		while (src[j] && (src[j] != ' ' && src[j] != '\t'))
			j++;
		dest[k] = (char *)malloc(sizeof(char) * (j - i + 1));
		if (!dest[k])
			return (ft_free_tab_len(dest, k), NULL);
		j = 0;
		while (src[i] && (src[i] != ' ' && src[i] != '\t'))
			dest[k][j++] = src[i++];
		dest[k++][j] = '\0';
	}
	dest[k] = NULL;
	return (dest);
}

char	**ft_split_space_tab(char const *s)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s) + 1));
	if (!tab)
		return (NULL);
	return (ft_str_cut(tab, s));
}
