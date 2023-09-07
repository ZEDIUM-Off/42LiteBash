/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:34:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/09/07 17:01:01 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minish.h>

t_uint	skip_parts(t_str str, t_quote_test *quotes)
{
	t_uint	i;
	t_uint	meta;

	i = 0;
	meta = get_meta_char(&str[i]);
	if (meta != NONE)
	{
		i++;
		if (meta == SINGLE_QUOTE)
			quotes->s_quote = !quotes->s_quote;
		if (meta == DOUBLE_QUOTE)
			quotes->d_quote = !quotes->d_quote;
		if (meta == DOLLAR)
			skip_to_space(str, &i);
		if (meta >= APPEND_REDIRECT && meta <= DOLLAR_D)
			i++;
	}
	else
	{
		if (quotes->s_quote || quotes->d_quote)
			while (str[i] && get_meta_char(&str[i]) == NONE)
				i++;
		skip_to_space(str, &i);
	}
	return (i);
}

t_uint	count_parts(t_str str)
{
	t_quote_test	quotes;
	t_uint			n_parts;
	t_uint			i;

	n_parts = 0;
	i = 0;
	quotes.s_quote = false;
	quotes.d_quote = false;
	while (str[i])
	{
		if (!quotes.s_quote && !quotes.d_quote)
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
		if (str[i])
			n_parts++;
		i += skip_parts(&str[i], &quotes);
	}
	printf("count_parts -> n_parts = %i\n", n_parts);
	return (n_parts);
}

t_uint	new_part(
	t_sh_context *shx, char **dest, t_str src, t_quote_test *quotes)
{
	t_uint	i;
	t_uint	j;

	j = 0;
	i = skip_parts(src, quotes);
	printf ("new_part -> src = [%s], i = %d\n", src, i);
	*dest = shx->gc->malloc(shx,
			sizeof(char) * (i + 1), true);
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

static t_str	*meta_cut(t_sh_context *shx, t_str *dest, t_str src)
{
	t_quote_test	quotes;
	t_uint			i;
	t_uint			k;
	t_uint			parts;

	i = 0;
	k = 0;
	parts = count_parts(src);
	quotes.s_quote = false;
	quotes.d_quote = false;
	while (src[i] && k < parts)
	{
		if (!quotes.s_quote && !quotes.d_quote)
			while (src[i] && (src[i] == ' ' || src[i] == '\t'))
				i++;
		i += new_part(shx, &dest[k], &src[i], &quotes);
		if (!dest[k])
			return (NULL);
		k++;
	}
	dest[k] = NULL;
	return (dest);
}

t_str	*split_parser(t_sh_context *shx, t_str line)
{
	t_str	*parts;

	parts = shx->gc->malloc(shx, sizeof(t_str)
			* (count_parts(line) + 1), true);
	if (!parts)
		return (printf("malloc failed\n"), NULL);
	return (meta_cut(shx, parts, line));
}
