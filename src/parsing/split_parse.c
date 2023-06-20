/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:34:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/06/20 15:26:33 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	skip_parts(t_str str)
{
	t_uint	i;
	t_uint	meta;

	i = 0;
	meta = get_meta_char(&str[i]);
	if (meta != NONE)
	{
		if (meta >= APPEND_REDIRECT && meta <= AND)
			i++;
		i++;
	}
	else
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t'
			&& get_meta_char(&str[i]) == NONE)
			i++;
	}
	return (i);
}

t_uint	count_parts(t_str str)
{
	t_uint	n_parts;
	t_uint	i;

	n_parts = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			n_parts++;
			i += skip_parts(&str[i]);
		}
		else
			i++;
	}
	return (n_parts);
}

t_uint	new_part(char **dest, t_str src)
{
	t_uint	i;
	t_uint	j;

	j = 0;
	i = skip_parts(src);
	*dest = g_shx->gc->malloc(sizeof(char) * (i + 1), true);
	if (!*dest)
		return (-1);
	while (j < i)
	{
		(*dest)[j] = src[j];
		j++;
	}
	(*dest)[j] = '\0';
	return (i);
}

static t_str	*meta_cut(t_str *dest, t_str src)
{
	t_uint	i;
	t_uint	k;

	i = 0;
	k = 0;
	while (src[i] && count_parts(src) - k > 0)
	{
		while (src[i] && (src[i] == ' ' || src[i] == '\t'))
			i++;
		i += new_part(&dest[k], &src[i]);
		if (!dest[k])
			return (NULL);
		k++;
	}
	dest[k] = NULL;
	return (dest);
}

t_str	*split_parser(t_str line)
{
	t_str	*parts;

	parts = g_shx->gc->malloc(sizeof(t_str)
			* (count_parts(line) + 1), true);
	if (!parts)
		return (printf("malloc failed\n"), NULL);
	return (meta_cut(parts, line));
}
