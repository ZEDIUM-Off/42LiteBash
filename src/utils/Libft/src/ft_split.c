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

static	size_t	ft_len_word(char const	*s, char c, size_t i, size_t n)
{
	if (n == 0)
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		return (i);
	}
	if (n == 1)
	{
		while (s[i] == c && c != '\0')
			i++;
		return (i);
	}
	return (0);
}

static void	ft_free(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static ssize_t	ft_split_iteration(char const *s, char c, char **strs,
	ssize_t nbword)
{
	ssize_t	i;
	size_t	len;
	size_t	start;

	len = 0;
	i = 0;
	start = 0;
	while (nbword > i + 1)
	{
		start = ft_len_word(s, c, len, 1);
		len = ft_len_word(s, c, start, 0) - start;
		strs[i] = ft_substr(s, start, len);
		if (strs[i] == NULL)
			return (ft_free(strs), -1);
		i++;
		len += start;
	}
	strs[i] = NULL;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	ssize_t	nbword;
	ssize_t	i;

	if (s == NULL)
		return (NULL);
	nbword = ft_cont_word(s, c);
	strs = malloc((sizeof(char *)) * (nbword) + 1);
	if (!strs)
		return (NULL);
	i = ft_split_iteration(s, c, strs, nbword);
	if (i == -1)
		return (NULL);
	strs[i] = NULL;
	return (strs);
}
