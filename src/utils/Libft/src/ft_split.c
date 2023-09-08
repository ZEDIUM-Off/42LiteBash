/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:26:09 by bfaure            #+#    #+#             */
/*   Updated: 2022/11/21 18:26:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

ssize_t	ft_cont_word(char const *s, char c)
{
	ssize_t	i;
	ssize_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		i++;
		if (s[i] == c && s[i - 1] != c)
			n++;
		if (s[i] == '\0' && s[i - 1] != c && c != '\0')
			n++;
	}
	return (n + 1);
}

static int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] != sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_str_cut(t_sh_context *shx,
	char **dest, char const *src, char sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (src[i] && ft_count_words(src, sep) - k > 0)
	{
		while (src[i] && src[i] == sep)
			i++;
		j = i;
		while (src[j] && src[j] != sep)
			j++;
		dest[k] = shx->gc->malloc(shx, sizeof(char)
				* (j - i + 1), false);
		if (!dest[k])
			return (ft_free_tab(shx, dest), NULL);
		j = 0;
		while (src[i] && src[i] != sep)
			dest[k][j++] = src[i++];
		dest[k++][j] = '\0';
	}
	dest[k] = NULL;
	return (dest);
}

char	**ft_split(t_sh_context *shx, char const *s, char c)
{
	char	**tabx;

	tabx = shx->gc->malloc(shx, sizeof(char *)
			* (ft_count_words(s, c) + 1), false);
	if (!tabx)
		return (NULL);
	return (ft_str_cut(shx, tabx, s, c));
}
